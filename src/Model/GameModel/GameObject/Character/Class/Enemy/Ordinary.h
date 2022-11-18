#pragma once
#include "IEnemyClass.h"

namespace GameModel {
class Ordinary : public IEnemyClass {
  GameModel::Abstract::Position last_character_position;

public:
    GameModel::Abstract::MapEntity get_map_entity() const noexcept override;
  Ordinary(std::string description, EnemySettings settings = EnemySettings());
  CharacterAction
  strategy(std::vector<GameModel::Abstract::MapEntityWithPosition> &cells,
           GameModel::Abstract::Position &pos) noexcept;
};
}; // namespace superrogue::GameObject::Character
