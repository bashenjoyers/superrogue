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
public:
  // returns how to display it on the map (can hide its class if smart enough (character characteristic))
  Abstract::MapEntity get_map_entity() const noexcept override;
  // creates an enemy class according to the description and settings
  Traveler(std::string description, EnemySettings settings = EnemySettings());
};
}; // namespace GameModel
