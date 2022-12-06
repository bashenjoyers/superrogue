#include "MapBuilder.h"
#include "Model/GameModel/Map/Generator/RandomGenerating/BinaryTreeMazeGenerator.h"
#include "Model/GameModel/GameObject/Character/Generation/FantasyEnemyFactory.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/generator.h"
#include "Model/GameModel/GameObject/Character/ICharacter.h"
#include "Model/GameModel/GameObject/Character/Person.h"

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

void MapBuilder::build() {
  map = mapGenerator->generate(opts);
  map[opts.width - 1][opts.height - 1] = Abstract::MapEntity::DOOR;

  for (int i = 0; i < enemiesCount; i++) {
	std::shared_ptr<IEnemy> enemy = buildEnemy(i);
	Abstract::Position pos = generatePosition();
	map[pos.x][pos.y] = enemy->get_map_entity();

	CharacterWithPosition enemyWithPosition(enemy);
	enemyWithPosition.pos = pos;
	enemies.push_back(enemyWithPosition);
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
	personWithPosition = std::make_shared<CharacterWithPosition>(person);
	personWithPosition->pos = pos;

	map[pos.x][pos.y] = person->get_map_entity();
  }
}

std::shared_ptr<IEnemy> MapBuilder::buildEnemy(int guid) {
  Abstract::EnemyClass
	  enemy_class_name = Values::enemy_classes[GameModel::Generation::enemy_class_i_gen(Values::generator)];
  std::shared_ptr<IEnemy> enemy;

  switch (enemy_class_name) {
  case Abstract::EnemyClass::AGRESSIVE: {
	enemy = enemyFactory->generateAgressive(guid);
  }
	break;

  case Abstract::EnemyClass::TRAVELER: {
	enemy = enemyFactory->generateTraveler(guid);
  }
	break;

  case Abstract::EnemyClass::REPLICATOR: {
      enemy = enemyFactory->generateReplicator(guid);
  }
      break;

  case Abstract::EnemyClass::ORDINARY: {
	enemy = enemyFactory->generateOrdinary(guid);
  }
	break;

  case Abstract::EnemyClass::INDIFFERENT: {
	enemy = enemyFactory->generateIndifferent(guid);
  }
	break;

  case Abstract::EnemyClass::FLYING: {
	enemy = enemyFactory->generateFlying(guid);
  }
	break;

  case Abstract::EnemyClass::COWARD: {
	enemy = enemyFactory->generateCoward(guid);
  }
	break;
  }

  return enemy;
}

std::vector<std::vector<Abstract::MapEntity>> MapBuilder::getMap() {
  return map;
}

std::vector<CharacterWithPosition> MapBuilder::getEnemies() {
  return enemies;
}

Abstract::Position MapBuilder::generatePosition() {
  std::uniform_int_distribution<size_t> xGen(0, opts.width - 1);
  std::uniform_int_distribution<size_t> yGen(0, opts.height - 1);

  while (true) {
	size_t x = xGen(Values::generator);
	size_t y = yGen(Values::generator);
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

std::map<Abstract::Position, std::shared_ptr<IItem>> MapBuilder::getItems() {
  return items;
}

void MapBuilder::setPerson(std::shared_ptr<Person> newPerson) {
  person = newPerson;
}

std::shared_ptr<CharacterWithPosition> MapBuilder::getPerson() {
  return personWithPosition;
}

}