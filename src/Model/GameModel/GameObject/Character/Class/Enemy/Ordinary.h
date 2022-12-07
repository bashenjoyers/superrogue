#pragma once
#include "IEnemyClass.h"

namespace GameModel {
/**
 * @brief Enemy class, which is created according to the description and settings
 * 
 * without any special features. He has an increased one of the characteristics
 * 
 */
class Ordinary : public IEnemyClass {
public:
  // returns how to display it on the map (can hide its class if smart enough (character characteristic))
  GameModel::Abstract::MapEntity get_map_entity() const noexcept override;
  // creates an enemy class according to the description and settings
  Ordinary(std::string description, EnemySettings settings = EnemySettings());
};
}; // namespace GameModel
