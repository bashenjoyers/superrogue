#pragma once
#include "IEnemyClass.h"

namespace GameModel {
/**
 * @brief Enemy class, which is created according to the description and settings
 * 
 * he can be located anywhere on the Map
 * 
 */
class Traveler : public IEnemyClass {
  // the last visible position of the character, used if he is this character is smart enough (character characteristic)
  Abstract::Position last_character_position;

public:
  // returns how to display it on the map (can hide its class if smart enough (character characteristic))
  Abstract::MapEntity get_map_entity() const noexcept override;
  Traveler(std::string description, EnemySettings settings = EnemySettings());
  // returns the strategy for the current class
  CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           Abstract::Position &pos) noexcept override;
};
}; // namespace GameModel
