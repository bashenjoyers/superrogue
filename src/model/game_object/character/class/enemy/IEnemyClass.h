#pragma once
#include "model/abstract.h"
#include "model/const.h"
#include "model/game_object/character/CharacterAction.h"
#include "model/game_object/character/class/ICharacterClass.h"
#include <random>

namespace superrogue::game_object::character {
struct EnemySettings {
  int visible_radius = DEFAULT_VISIBLE_RADIUS;
  bool ignore_walls = false;
  float intellect = 1; // [0..1]
  int attack_range = 1;
};

class IEnemyClass : public ICharacterClass {
  EnemySettings settings;

public:
  EnemySettings get_settings() const noexcept;
  virtual superrogue::abstract::MapEntity get_map_entity() const noexcept {
    return superrogue::abstract::MapEntity::ENEMY;
  };
  bool is_vacant(superrogue::abstract::MapEntity map_entity) const noexcept;
  superrogue::game_object::character::CharacterAction default_fight_behavior(
      int dx, int dy,
      std::vector<superrogue::game_object::character::CharacterAction>
          &possible_actions,
      bool can_punch = true) const noexcept;
  superrogue::game_object::character::CharacterAction
  strategy(std::vector<superrogue::abstract::MapEntityWithPosition> &cells,
           superrogue::abstract::Position &pos) noexcept;
  IEnemyClass(std::string description, EnemySettings settings);
  virtual ~IEnemyClass() {}

protected:
  superrogue::abstract::Position last_character_position;
};
}; // namespace superrogue::game_object::character
