#pragma once
#include "IEnemyClass.h"

namespace GameModel {
class Indifferent : public IEnemyClass {
  Abstract::Position last_character_position;
  bool disturbed = false;

public:
  void disturb() noexcept;
  Abstract::MapEntity get_map_entity() const noexcept override;
  Indifferent(std::string description,
              EnemySettings settings = EnemySettings());
  CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           Abstract::Position &pos) noexcept;
};
}; // namespace GameModel
