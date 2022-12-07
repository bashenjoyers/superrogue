#pragma once
#include "Model/GameModel/GameObject/Character/Enemy.h"

namespace GameModel {
/**
 * @brief Enemy class, which is created according to the description and settings
 * 
 * always runs from the hero if he sees him. dexterity is 3 times more than normal
 * 
 */
class Coward : public Enemy {
public:
  // returns how to display it on the map (can hide its class if smart enough (character characteristic))
  GameModel::Abstract::MapEntity get_map_entity() const noexcept override;
  // creates an enemy class according to the description and settings
  Coward(std::string name,
         std::string description,
         Characteristics characteristics,
         int id, EnemySettings settings = EnemySettings());
};
}; // namespace GameModel
