#pragma once
#include "IEnemyClass.h"

namespace GameModel {
class Agressive : public IEnemyClass {
  Abstract::Position last_character_position;

public:
  Abstract::MapEntity get_map_entity() const noexcept override;
  Agressive(std::string description, EnemySettings settings = EnemySettings());
  CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           Abstract::Position &pos) noexcept override;
};
}; // namespace GameModel
