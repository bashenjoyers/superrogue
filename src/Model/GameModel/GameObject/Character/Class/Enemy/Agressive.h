#pragma once
#include "Model/GameModel/GameObject/Character/Enemy.h"

namespace GameModel {
/**
 * @brief Enemy class, which is created according to the description and settings
 * 
 * if he sees at least someone (not necessarily a Character
 * 
 */
class Agressive : public Enemy {
public:
  // returns how to display it on the map (can hide its class if smart enough (character characteristic))
  Abstract::MapEntity get_map_entity() const noexcept override;
  // creates an enemy class according to the description and settings
  Agressive(std::string name,
            Characteristics characteristics,
            int id, EnemySettings settings = EnemySettings());
  // returns the strategy for the current class
  CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           const Abstract::Position &pos) noexcept override;
};
}; // namespace GameModel
