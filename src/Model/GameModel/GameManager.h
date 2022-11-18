#pragma once

#include "Model/GameModel/GameObject/Character/Enemy.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/Map/Map.h"

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

class GameManager {
  int level = 0;
  Person person;
  Map::MapOptions map_options;
  Person generate_person() noexcept;
  std::set<Enemy> generate_enemies(GameOptions game_options);
  Characteristics
  generate_characteristics(float characteristic_k) const noexcept;
  GameOptions generate_game_options() noexcept;
  void person_level_up(Characteristics characteristics);

public:
  GameManager(Map::MapOptions map_options);
  std::shared_ptr<Map::Map> generate_map() noexcept;
};

}; // namespace GameModel
