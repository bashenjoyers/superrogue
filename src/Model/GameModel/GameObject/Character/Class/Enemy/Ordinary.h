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
  // the last visible position of the character, used if he is this character is smart enough (character characteristic)
  GameModel::Abstract::Position last_character_position;

public:
  // returns how to display it on the map (can hide its class if smart enough (character characteristic))
  GameModel::Abstract::MapEntity get_map_entity() const noexcept override;
  Ordinary(std::string description, EnemySettings settings = EnemySettings());
  CharacterAction
  // returns the strategy for the current class
  strategy(std::vector<GameModel::Abstract::MapEntityWithPosition> &cells,
           const GameModel::Abstract::Position &pos) noexcept override;
};
}; // namespace GameModel
