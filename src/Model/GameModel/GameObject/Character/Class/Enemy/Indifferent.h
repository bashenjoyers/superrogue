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
public:
  // sets flag not ignore in states
  void disturb() noexcept;
  // returns how to display it on the map (can hide its class if smart enough (character characteristic))
  Abstract::MapEntity get_map_entity() const noexcept override;
  // creates an enemy class according to the description and settings
  Indifferent(std::string description,
              EnemySettings settings = EnemySettings());
};
}; // namespace GameModel
