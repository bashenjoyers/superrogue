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
  generateMap();
}

std::shared_ptr<Person> GameManager::generate_person() noexcept {
  string firstname =
	  firstnames[GameModel::Generation::firstname_i_gen(Values::generator)];
  string lastname =
	  lastnames[GameModel::Generation::lastname_i_gen(Values::generator)];
  PersonClass person_classes_name =
	  person_classes[GameModel::Generation::person_class_i_gen(
		  Values::generator)];

  return get_person(person_classes_name, lastname + " " + firstname);
}

void GameManager::person_level_up(Characteristics characteristics) {
  person->level_up(characteristics);
}

void GameManager::generateMap() noexcept {
  if (level != 1) {
	person_level_up(Characteristics(2, 2, 0, 1)); // user can choose it later
  }

  auto enemyFactory = std::make_shared<Generation::FantasyEnemyFactory>(level);
  auto itemGenerator = std::make_shared<Generation::ItemGenerator>(level, person->get_full_characteristics().luck);
  auto mapGenerator = std::make_shared<Generation::Map::BinaryTreeMazeGenerator>();
  std::shared_ptr<Generation::Map::MapBuilder> builder = std::make_shared<Generation::Map::MapBuilder>();
  builder->setEnemiesFactory(enemyFactory);
  builder->setItemsGenerator(itemGenerator);
  builder->setMapGenerator(mapGenerator);
  builder->setMapOptions(map_options);
  builder->setEnemiesCount(enemyCount);
  builder->setItemsCount(itemsCount);
  builder->setPerson(person);

  auto world = std::make_shared<Map::World>(builder->build());
  worldManipulator = std::make_shared<Map::WorldManipulator>(world, level, itemGenerator);

  status = GameStatus::IN_PROGRESS;
  level++;
}

void GameManager::step(CharacterAction action) {
  assert(person != nullptr);
  assert(worldManipulator != nullptr);

  if (!worldManipulator->act(action, person)) {
	if (!worldManipulator->actPersonInternal(action, person)) {
	  return;
	}
  }

  if (worldManipulator->isDoorCell(person->get_position().x, person->get_position().y)) {
	generateMap();
	return;
  }

  worldManipulator->enemiesAct();

  if (person->is_dead()) {
	status = GameStatus::END;
  }

  return;
}

Map::MapInfo GameManager::getMapInfo() {
  assert(worldManipulator != nullptr);
  return worldManipulator->getMapInfo();
}
bool GameManager::isOver() {
  return status == GameStatus::END;
}

}; // namespace GameModel
