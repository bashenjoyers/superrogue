#include "MapBuilder.h"
#include "Model/GameModel/Map/Generator/RandomGenerating/BinaryTreeMazeGenerator.h"
#include "Model/GameModel/GameObject/Character/Generation/FantasyEnemyFactory.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/generation_utils.h"
#include "Model/GameModel/GameObject/Character/ICharacter.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include "Model/GameModel/values.h"

namespace GameModel::Generation::Map {
MapBuilder::MapBuilder() {
  reset();
}

void MapBuilder::reset() {
  enemiesCount = 0;
  mapGenerator = std::make_unique<BinaryTreeMazeGenerator>();
  enemyFactory = std::make_shared<FantasyEnemyFactory>(0);
  itemGenerator = std::make_shared<ItemGenerator>(0, 1.f);
  opts = GameModel::Map::MapOptions();
}

void MapBuilder::setEnemiesFactory(std::shared_ptr<AbstractEnemyFactory> newEnemyFactory) {
  enemyFactory = newEnemyFactory;
}

void MapBuilder::setEnemiesCount(size_t count) {
  enemiesCount = count;
}

void MapBuilder::setMapGenerator(std::shared_ptr<MapGenerator> newGenerator) {
  mapGenerator = newGenerator;
}

void MapBuilder::setMapOptions(GameModel::Map::MapOptions newOpts) {
  opts = newOpts;
}

GameModel::Map::World MapBuilder::build() {
  map = mapGenerator->generate(opts);
  Abstract::Position door = {opts.width - 1, opts.height - 1};
  map[door.x][door.y] = Abstract::MapEntity::DOOR;

  for (int i = 0; i < enemiesCount; i++) {
	std::shared_ptr<Enemy> enemy = buildEnemy();
	Abstract::Position pos = generatePosition();
	enemy->set_position(pos);

	map[enemy->get_position().x][enemy->get_position().y] = enemy->get_map_entity();
	enemies.push_back(enemy);
  }

  for (size_t i = 0; i < itemsCount; i++) {
	std::shared_ptr<IItem> item = buildItem();
	if (item != nullptr) {
	  Abstract::Position pos = generatePosition();
	  map[pos.x][pos.y] = item->getMapEntity();

	  items[pos] = item;
	}
  }

  if (person != nullptr) {
	Abstract::Position pos = generatePosition();
	person->set_position(pos);

	map[pos.x][pos.y] = person->get_map_entity();
  }

  return GameModel::Map::World{
	  .map_options = opts,
	  .enemies = enemies,
	  .person = person,
	  .map = map,
	  .door = door,
	  .items = items
  };
}

std::shared_ptr<Enemy> MapBuilder::buildEnemy() {
  Abstract::EnemyClass
	  enemy_class_name = Values::enemy_classes[GameModel::Generation::enemy_class_i_gen(Values::generator)];
  std::shared_ptr<Enemy> enemy;

  switch (enemy_class_name) {
  case Abstract::EnemyClass::AGRESSIVE: {
	enemy = enemyFactory->generateAgressive();
  }
	break;

  case Abstract::EnemyClass::TRAVELER: {
	enemy = enemyFactory->generateTraveler();
  }
	break;

  case Abstract::EnemyClass::ORDINARY: {
	enemy = enemyFactory->generateOrdinary();
  }
	break;

  case Abstract::EnemyClass::INDIFFERENT: {
	enemy = enemyFactory->generateIndifferent();
  }
	break;

  case Abstract::EnemyClass::FLYING: {
	enemy = enemyFactory->generateFlying();
  }
	break;

  case Abstract::EnemyClass::COWARD: {
	enemy = enemyFactory->generateCoward();
  }
	break;
  case Abstract::EnemyClass::REPLICATOR: {
    enemy = enemyFactory->generateReplicator();
  }
  }

  return enemy;
}

Abstract::Position MapBuilder::generatePosition() {
  std::uniform_int_distribution<int> xGen(0, opts.width - 1);
  std::uniform_int_distribution<int> yGen(0, opts.height - 1);

  while (true) {
	int x = xGen(Values::generator);
	int y = yGen(Values::generator);
	if (map[x][y] == Abstract::MapEntity::FLOOR) {
	  return {x, y};
	}
  }
}

void MapBuilder::setItemsCount(size_t count) {
  itemsCount = count;
}

std::shared_ptr<IItem> MapBuilder::buildItem() {
  std::shared_ptr<IItem> item = itemGenerator->generate();
  return item;
}

void MapBuilder::setItemsGenerator(std::shared_ptr<ItemGenerator> newItemGenerator) {
  itemGenerator = newItemGenerator;
}

void MapBuilder::setPerson(std::shared_ptr<Person> newPerson) {
  person = newPerson;
}

}