#pragma once
#include "IEnemyClass.h"

namespace GameModel {
/**
 * @brief Enemy class, which is created according to the description and settings
 * 
 * ignores everyone if he doesn't start hitting first
 * 
 */
class Indifferent : public IEnemyClass {
  // the last visible position of the character, used if he is this character is smart enough (character characteristic)
  Abstract::Position last_character_position;
  // whether the character was hit. Strategy changes if so
  bool disturbed = false;

public:
  // sets flag disturbed in true
  void disturb() noexcept;
  // returns how to display it on the map (can hide its class if smart enough (character characteristic))
  Abstract::MapEntity get_map_entity() const noexcept override;
  Indifferent(std::string description,
              EnemySettings settings = EnemySettings());
  // returns the strategy for the current class
  CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           Abstract::Position &pos) noexcept override;
};
}; // namespace GameModel
