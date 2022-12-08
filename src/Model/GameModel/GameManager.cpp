#include "GameManager.h"
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/GameObject/Character/Enemy.h"
#include "Model/GameModel/GameObject/Character/IConfusionEnemy.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include "Model/GameModel/Inventory/Inventory.h"
#include "Model/GameModel/GameObject/Character/Generation/FantasyEnemyFactory.h"
#include "Model/GameModel/Map/Generator/RandomGenerating/BinaryTreeMazeGenerator.h"
#include "abstract.h"
#include "generation_utils.h"
#include "values.h"
#include "Model/GameModel/Map/MapBuilder.h"
#include <memory>
#include <cassert>

using std::max;
using std::set;
using std::string;
using std::vector;

namespace GameModel {

using namespace Values;
using namespace Abstract;

GameManager::GameManager(Map::MapOptions map_options)
	: map_options(map_options) {
  person = generate_person();
  mapGenerator = std::make_shared<Generation::Map::BinaryTreeMazeGenerator>();
  generateMap();
}

Characteristics GameManager::generate_characteristics(
	float characteristic_k = 1) const noexcept {
  int points = int(level * POINTS_IN_LVL * characteristic_k);
  int health_default = int(level * HEALTH_LVL_K * characteristic_k);
  int damage =
	  int(GameModel::Generation::characteristic_gen(Values::generator) /
		  PARAMETER_COUNT * points) + 1;
  int armor = int(GameModel::Generation::characteristic_gen(Values::generator) /
	  PARAMETER_COUNT * points) + 1;
  int health =
	  int(GameModel::Generation::characteristic_gen(Values::generator) /
		  PARAMETER_COUNT * points);
  int dexterity =
	  int(GameModel::Generation::characteristic_gen(Values::generator) /
		  PARAMETER_COUNT * points);
  float luck = GameModel::Generation::luck_gen(Values::generator);
  return Characteristics(damage, armor, health_default + health, dexterity,
						 luck);
}

std::shared_ptr<Person> GameManager::generate_person() noexcept {
  string firstname =
	  firstnames[GameModel::Generation::firstname_i_gen(Values::generator)];
  string lastname =
	  lastnames[GameModel::Generation::lastname_i_gen(Values::generator)];
  PersonClass person_classes_name =
	  person_classes[GameModel::Generation::person_class_i_gen(
		  Values::generator)];
  PersonSettings settings = PersonSettings();
  if (person_classes_name == PersonClass::FARSIGHTED) {
	settings.visible_radius = settings.visible_radius * 2;
  }
  if (person_classes_name == PersonClass::SECRETIVE) {
	settings.other_visible_k = SECRETIVE_VISIBILITY_K;
  }
  if (person_classes_name == PersonClass::WISE) {
	settings.visible_enemy = true;
  }

  Characteristics characteristics = generate_characteristics();
  level--; // internal need;
  if (person_classes_name == PersonClass::LUCKY) {
	characteristics.luck = max(characteristics.luck, LUCKY_LUCK);
  }
  int potions_max = (person_classes_name == PersonClass::ALCHEMIST)
					? POTIONS_MAX_ALCHEMIST
					: DEFAULT_POTIONS_MAX;
  Inventory::Inventory inventory = Inventory::Inventory(potions_max);
  std::shared_ptr<IPersonClass> person_class = get_person_class(person_classes_name, settings);
  return std::make_shared<Person>(lastname + " " + firstname, characteristics, person_class,
								  inventory);
}

void GameManager::person_level_up(Characteristics characteristics) {
  person->level_up(characteristics);
}

void GameManager::generateMap() noexcept {
  level++;
  if (level != 1) {
	person_level_up(Characteristics(2, 2, 0, 1)); // user can choose it later
  }

  enemyFactory = std::make_shared<Generation::FantasyEnemyFactory>(level);
  itemGenerator = std::make_shared<Generation::ItemGenerator>(level, person->get_full_characteristics().luck);
  std::shared_ptr<Generation::Map::MapBuilder> builder = std::make_shared<Generation::Map::MapBuilder>();
  builder->setEnemiesFactory(enemyFactory);
  builder->setItemsGenerator(itemGenerator);
  builder->setMapGenerator(mapGenerator);
  builder->setMapOptions(map_options);
  builder->setEnemiesCount(enemyCount);
  builder->setItemsCount(itemsCount);
  builder->setPerson(person);

  world = std::make_shared<Map::World>(builder->build());
  worldManipulator = std::make_shared<Map::WorldManipulator>(world, level, itemGenerator);

  status = GameStatus::IN_PROGRESS;
}

bool GameManager::step(CharacterAction action) {
  assert(world != nullptr);
  assert(person != nullptr);
  assert(worldManipulator != nullptr);

  if (!worldManipulator->act(action, world->person)) {
	if (!worldManipulator->actPersonInternal(action, world->person)) {
	  return false;
	}
  }

  if (world->person->get_position() == world->door) {
	generateMap();
	return true;
  }

  worldManipulator->enemiesAct();

  if (person->isDead()) {
	status = GameStatus::END;
  }

  return true;
}

Map::MapInfo GameManager::getMapInfo() {
  assert(worldManipulator != nullptr);
  return worldManipulator->getMapInfo();
}
bool GameManager::isOver() {
  return status == GameStatus::END;
}

}; // namespace GameModel
