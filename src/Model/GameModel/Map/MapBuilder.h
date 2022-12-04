#pragma once

#include <cstddef>
#include <map>

#include "Model/GameModel/Map/Generator/MapGenerator.h"
#include "Model/GameModel/GameObject/Character/Generation/AbstractEnemyFactory.h"
#include "Model/GameModel/GameObject/Item/Generation/ItemGenerator.h"
#include "Model/GameModel/GameObject/Character/Person.h"

namespace GameModel::Generation::Map {

/**
 * @brief Pattern builder for map generation
 */
// TODO separate to enemy generation?
class MapBuilder {
public:
  /**
   * @brief Map builder constructor
   */
  MapBuilder();

  /**
   * @brief reset all settings
   */
  void reset();

  /**
   * @brief set enemy factory from which enemy generation will be done
   * @param newEnemyFactory enemy factory
   */
  void setEnemiesFactory(std::shared_ptr<AbstractEnemyFactory> newEnemyFactory);
  /**
   * @brief set enemies count
   * @param count
   */
  void setEnemiesCount(size_t count);

  /**
   * @brief set item generator from which items generation will be done
   * @param newItemGenerator
   */
  void setItemsGenerator(std::shared_ptr<ItemGenerator> newItemGenerator);
  /**
   * @brief set items count
   * @param count
   */
  void setItemsCount(size_t count);

  /**
   * @brief set map generator from which map generation will be done
   * @param newGenerator
   */
  void setMapGenerator(std::shared_ptr<MapGenerator> newGenerator);
  /**
   * @brief set map options
   * @param newOpts
   */
  void setMapOptions(GameModel::Map::MapOptions newOpts);

  /**
   * @brief set main hero for generation
   * @param newPerson
   */
  void setPerson(std::shared_ptr<Person> newPerson);

  /**
   * @brief generate whole map based on set configuration
   */
  void build();

  std::vector<std::vector<Abstract::MapEntity>> getMap();
  std::vector<CharacterWithPosition> getEnemies();
  std::map<Abstract::Position, std::shared_ptr<IItem>> getItems();
  std::shared_ptr<CharacterWithPosition> getPerson();

private:
  std::shared_ptr<IEnemy> buildEnemy(int guid);
  Abstract::Position generatePosition();
  std::shared_ptr<IItem> buildItem();

  std::shared_ptr<ItemGenerator> itemGenerator;
  std::shared_ptr<MapGenerator> mapGenerator;
  std::shared_ptr<AbstractEnemyFactory> enemyFactory;
  std::shared_ptr<Person> person;

  GameModel::Map::MapOptions opts;
  size_t enemiesCount = 0;
  size_t itemsCount = 0;

  std::vector<std::vector<Abstract::MapEntity>> map;
  std::vector<CharacterWithPosition> enemies;
  std::map<Abstract::Position, std::shared_ptr<IItem>> items;
  std::shared_ptr<CharacterWithPosition> personWithPosition;
};

}