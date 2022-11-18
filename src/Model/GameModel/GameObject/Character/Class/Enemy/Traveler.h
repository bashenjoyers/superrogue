#pragma once
#include "IEnemyClass.h"

namespace GameModel {
class Traveler : public IEnemyClass {
  Abstract::Position last_character_position;

public:
  Abstract::MapEntity get_map_entity() const noexcept override;
  Traveler(std::string description, EnemySettings settings = EnemySettings());
  CharacterAction
  strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
           Abstract::Position &pos) noexcept;
};
}; // namespace superrogue::GameObject::Character
