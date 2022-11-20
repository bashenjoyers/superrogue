#pragma once
#include "Model/GameModel/GameObject/Character/CharacterAction.h"
#include "Model/GameModel/GameObject/Character/Class/ICharacterClass.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/const.h"
#include <random>

namespace GameModel {
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
  virtual Abstract::MapEntity get_map_entity() const noexcept {
    return Abstract::MapEntity::ENEMY;
  };
  bool is_vacant(Abstract::MapEntity map_entity) const noexcept;
  CharacterAction
  default_fight_behavior(int dx, int dy,
                         std::vector<CharacterAction> &possible_actions,
                         bool can_punch = true) const noexcept;
  virtual CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           Abstract::Position &pos) noexcept;
  IEnemyClass(std::string description, EnemySettings settings);
  virtual ~IEnemyClass() {}

protected:
  Abstract::Position last_character_position;
};
}; // namespace GameModel
