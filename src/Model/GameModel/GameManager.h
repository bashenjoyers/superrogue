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
  size_t enemyCount = 0;  // TODO on generation
  size_t itemsCount = 8;

  int level = 1;
  std::shared_ptr<Person> person;

  Map::MapOptions map_options;
  Map::World map_ref;

  std::shared_ptr<Person> generate_person() noexcept;
  Characteristics generate_characteristics(float characteristic_k) const noexcept;
  void person_level_up(Characteristics characteristics);

  std::shared_ptr<Generation::AbstractEnemyFactory> enemyFactory;
  std::shared_ptr<Generation::ItemGenerator> itemGenerator;
  std::shared_ptr<Generation::Map::MapGenerator> mapGenerator;

  std::shared_ptr<Map::World> world;
  std::shared_ptr<Map::WorldManipulator> worldManipulator;

  Abstract::GameStatus status;

  // TODO BAGRORG CHANGE ITEM
public:
  /**
   * @brief Construct a new Game Manager object. 
   * 
   * @param map_options - parameters used when generating a map
   */
  GameManager(Map::MapOptions map_options);

  /**
   * @brief Generates a map and everything you need to play. After completing the level and at the beginning of the game, you need to call the generation of the map (the old map stops processing requests)
   * 
   * @return std::shared_ptr<Map::Map> - ref to created field
   */
  void generateMap() noexcept;

  bool step(CharacterAction action);

  Map::MapInfo getMapInfo();
  bool isOver();
};

}; // namespace GameModel
