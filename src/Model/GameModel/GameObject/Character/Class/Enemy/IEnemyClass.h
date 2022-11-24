#pragma once
#include "Model/GameModel/GameObject/Character/CharacterAction.h"
#include "Model/GameModel/GameObject/Character/Class/ICharacterClass.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/const.h"
#include <random>

namespace GameModel {
/**
 * @brief enemy character settings
 * 
 */
struct EnemySettings {
  // just visibility radius
  int visible_radius = DEFAULT_VISIBLE_RADIUS;
  // can a character of this class walk through walls
  bool ignore_walls = false;
  // internal parameter for the class, affects the behavior and visibility on the map
  float intellect = 1; // [0..1]
  // attack range (can be melee or ranged like character)
  int attack_range = 1;
};

/**
 * @brief base class for enemy 'class' (type)
 */
class IEnemyClass : public ICharacterClass {
  // enemy settings
  EnemySettings settings;

public:
  // return enemy settings
  EnemySettings get_settings() const noexcept;
  // returns how to display the character on the map
  virtual Abstract::MapEntity get_map_entity() const noexcept {
    return Abstract::MapEntity::ENEMY;
  };
  // returns whether this cell is empty for the character of the current class
  bool is_vacant(Abstract::MapEntity map_entity) const noexcept;
  // default behavior provided that he sees the character
  CharacterAction
  default_fight_behavior(int dx, int dy,
                         std::vector<CharacterAction> &possible_actions,
                         bool can_punch = true) const noexcept;
  // returns the strategy for the current class
  virtual CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           const Abstract::Position &pos) noexcept;
  // Create Enemy class according to the description and settings
  IEnemyClass(std::string description, EnemySettings settings);
  virtual ~IEnemyClass() {}

protected:
  // the last visible position of the character, used if he is this character is smart enough (character characteristic)
  Abstract::Position last_character_position;
};
}; // namespace GameModel
