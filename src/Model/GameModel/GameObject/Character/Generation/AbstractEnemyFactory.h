#pragma once

#include "Model/GameModel/GameObject/Character/Enemy.h"

#include <memory>

namespace GameModel::Generation {
class AbstractEnemyFactory {
public:
  AbstractEnemyFactory(size_t level) : level(level) {}
  ~AbstractEnemyFactory() = default;

  virtual std::shared_ptr<Enemy> generateAgressive() = 0;
  virtual std::shared_ptr<Enemy> generateCoward() = 0;
  virtual std::shared_ptr<Enemy> generateFlying() = 0;
  virtual std::shared_ptr<Enemy> generateIndifferent() = 0;
  virtual std::shared_ptr<Enemy> generateOrdinary() = 0;
  virtual std::shared_ptr<Enemy> generateTraveler() = 0;
  virtual std::shared_ptr<Enemy> generateReplicator() = 0;

protected:
  Characteristics generateCharacteristics();
  EnemySettings generateSettings();

  size_t level;
};
}
