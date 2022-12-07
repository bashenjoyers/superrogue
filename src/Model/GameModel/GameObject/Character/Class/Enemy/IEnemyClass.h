#pragma once
#include "Model/GameModel/GameObject/Character/CharacterAction.h"
#include "Model/GameModel/GameObject/Character/Class/ICharacterClass.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/const.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/state/EnemyEnvironmentInfo.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/state/helpers.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/state/EnemyState.h"
#include <random>
#include <unordered_set>
#include <optional>

namespace GameModel {
/**
 * @brief base class for enemy 'class' (type)
 */
class IEnemyClass : public ICharacterClass {
public:
  // return enemy settings
  EnemySettings get_settings() const noexcept;
  // returns how to display the character on the map
  virtual Abstract::MapEntity get_map_entity() const noexcept {
    return Abstract::MapEntity::ENEMY;
  };
  // strategy change to coward
  void scare() noexcept;
  // returns the strategy for the current class
  virtual CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                           const Abstract::Position &pos) noexcept;
  // Create Enemy class according to the description and settings
  IEnemyClass(std::string description, EnemyStateHolder state_holder);
  virtual ~IEnemyClass() {}

protected:
  // stores and manages states
  EnemyStateHolder state_holder;
};
}; // namespace GameModel
