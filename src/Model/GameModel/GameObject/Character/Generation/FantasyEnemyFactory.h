#pragma once

#include "AbstractEnemyFactory.h"

namespace GameModel::Generation {

class FantasyEnemyFactory : public AbstractEnemyFactory {
public:
  FantasyEnemyFactory(size_t level) : AbstractEnemyFactory(level) {}

  std::shared_ptr<Enemy> generateAgressive(int guid) override;

  std::shared_ptr<Enemy> generateCoward(int guid) override;

  std::shared_ptr<Enemy> generateFlying(int guid) override;

  std::shared_ptr<Enemy> generateIndifferent(int guid) override;

  std::shared_ptr<Enemy> generateOrdinary(int guid) override;

  std::shared_ptr<Enemy> generateTraveler(int guid) override;

  std::shared_ptr<Enemy> generateReplicator(int guid) override;

private:

};

}