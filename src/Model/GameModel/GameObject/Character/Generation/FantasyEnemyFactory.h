#pragma once

#include "AbstractEnemyFactory.h"

namespace GameModel::Generation {

class FantasyEnemyFactory : public AbstractEnemyFactory {
public:
  FantasyEnemyFactory(size_t level) : AbstractEnemyFactory(level) {}

  std::shared_ptr<Enemy> generateAgressive(const Abstract::Position& pos) override;

  std::shared_ptr<Enemy> generateCoward(const Abstract::Position& pos) override;

  std::shared_ptr<Enemy> generateFlying(const Abstract::Position& pos) override;

  std::shared_ptr<Enemy> generateIndifferent(const Abstract::Position& pos) override;

  std::shared_ptr<Enemy> generateOrdinary(const Abstract::Position& pos) override;

  std::shared_ptr<Enemy> generateTraveler(const Abstract::Position& pos) override;

  std::shared_ptr<Enemy> generateReplicator(const Abstract::Position& pos) override;

private:

};

}