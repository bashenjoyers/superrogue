#pragma once

#include "Model/GameModel/GameObject/Character/Enemy.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/Map/World.h"

#include "values.h"
#include "Model/GameModel/Manipulators/WorldManipulator.h"
#include "Model/GameModel/Map/Generator/MapGenerator.h"
#include "Model/GameModel/GameObject/Character/Generation/AbstractEnemyFactory.h"
#include <iostream>
#include <memory>
#include <random>
#include <set>
#include <vector>

namespace GameModel {
struct GameOptions {
  int enemies_count;
};

/**
 * @brief a class that creates a field, characters on it and auxiliary entities
 * 
 */
class GameManager {
  size_t enemyCount = 10;
  size_t itemsCount = 8;

  int level = 1;
  std::shared_ptr<Person> person;

  Map::MapOptions map_options;

  std::shared_ptr<Person> generate_person() noexcept;
  void person_level_up(Characteristics characteristics);

  std::shared_ptr<Map::WorldManipulator> worldManipulator;

  Abstract::GameStatus status;

  void generateMap() noexcept;

  std::shared_ptr<Map::World> world;
public:
  /**
   * @brief Construct a new Game Manager object. 
   * 
   * @param map_options - parameters used when generating a map
   */
  GameManager(Map::MapOptions map_options);


  /**
   * @brief Make a step based on Character Action
   * @param action to handle
   * @return
   */
  void step(CharacterAction action);

  /**
   * @brief get current map information
   * @return Map information
   */
  Map::MapInfo getMapInfo();

  /**
   * @brief Is game over
   * @return true if game is over
   */
  bool isOver();
};

}; // namespace GameModel
