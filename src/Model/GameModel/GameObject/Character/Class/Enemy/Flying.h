#pragma once
#include "IEnemyClass.h"

namespace GameModel {
class Flying : public IEnemyClass {
  Abstract::Position last_character_position;

public:
  Abstract::MapEntity get_map_entity() const noexcept override;
  Flying(std::string description, EnemySettings settings = EnemySettings());
  CharacterAction
  strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
           Abstract::Position &pos) noexcept;
};
}; // namespace superrogue::GameObject::Character
