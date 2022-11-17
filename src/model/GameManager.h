#pragma once

#include "controller/events/IEvent.h"
#include "model/game_object/character/Enemy.h"
#include "model/game_object/character/Person.h"
#include "model/map/Map.h"
#include "model/values.h"
#include <iostream>
#include <random>
#include <set>
#include <vector>

namespace superrogue::game_manager {
struct GameOptions {
  int enemies_count;
};

class GameManager {
  int level = 0;
  superrogue::game_object::character::Person person;
  superrogue::map::MapOptions map_options;
  superrogue::game_object::character::Person generate_person() noexcept;
  std::set<superrogue::game_object::character::Enemy>
  generate_enemies(GameOptions game_options);
  Characteristics
  generate_characteristics(float characteristic_k) const noexcept;
  GameOptions generate_game_options() noexcept;
  void person_level_up(Characteristics characteristics);

public:
  GameManager(superrogue::map::MapOptions map_options);
  std::vector<superrogue::controller::event::IEvent> events() noexcept;
  std::shared_ptr<superrogue::map::Map> generate_map() noexcept;
};
}; // namespace superrogue::game_manager
