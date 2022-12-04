#pragma once

#include "Model/GameModel/GameObject/Character/Enemy.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/Map/World.h"

#include "values.h"
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
  int level = 1;
  std::shared_ptr<Person> person;
  Map::MapOptions map_options;
  std::shared_ptr<Map::World> map_ref;
  std::shared_ptr<Person> generate_person() noexcept;
  std::set<std::shared_ptr<IEnemy>> generate_enemies(GameOptions game_options);
  Characteristics
  generate_characteristics(float characteristic_k) const noexcept;
  GameOptions generate_game_options() noexcept;
  void person_level_up(Characteristics characteristics);

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
  std::shared_ptr<Map::World> generate_map() noexcept;
};

}; // namespace GameModel
