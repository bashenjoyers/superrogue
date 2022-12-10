#pragma once

#include "Model/GameModel/GameObject/Character/Enemy.h"

#include <memory>

namespace GameModel::Generation {
class AbstractEnemyFactory {
public:
  AbstractEnemyFactory(size_t level) : level(level) {}
  ~AbstractEnemyFactory() = default;

  virtual std::shared_ptr<Enemy> generateAgressive(const Abstract::Position& pos) = 0;
  virtual std::shared_ptr<Enemy> generateCoward(const Abstract::Position& pos) = 0;
  virtual std::shared_ptr<Enemy> generateFlying(const Abstract::Position& pos) = 0;
  virtual std::shared_ptr<Enemy> generateIndifferent(const Abstract::Position& pos) = 0;
  virtual std::shared_ptr<Enemy> generateOrdinary(const Abstract::Position& pos) = 0;
  virtual std::shared_ptr<Enemy> generateTraveler(const Abstract::Position& pos) = 0;
  virtual std::shared_ptr<Enemy> generateReplicator(const Abstract::Position& pos) = 0;

protected:
  Characteristics generateCharacteristics();
  EnemySettings generateSettings(Abstract::EnemyClass enemy_class, const Abstract::Position& pos);

  size_t level;
};
}
