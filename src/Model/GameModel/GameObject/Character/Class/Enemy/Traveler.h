#pragma once
#include "Model/GameModel/GameObject/Character/Enemy.h"

namespace GameModel {
/**
 * @brief Enemy class, which is created according to the description and settings
 * 
 * he can be located anywhere on the Map
 * 
 */
class Traveler : public Enemy {
public:
  // returns how to display it on the map (can hide its class if smart enough (character characteristic))
  Abstract::MapEntity get_map_entity() const noexcept override;
  // creates an enemy class according to the description and settings
  Traveler(std::string name,
           Characteristics characteristics,
           int id, EnemySettings settings = EnemySettings());
};
}; // namespace GameModel
