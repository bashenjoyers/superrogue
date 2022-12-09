#pragma once

#include "AbstractEnemyFactory.h"

namespace GameModel::Generation {

class FantasyEnemyFactory : public AbstractEnemyFactory {
public:
  FantasyEnemyFactory(size_t level) : AbstractEnemyFactory(level) {}

  std::shared_ptr<Enemy> generateAgressive() override;

  std::shared_ptr<Enemy> generateCoward() override;

  std::shared_ptr<Enemy> generateFlying() override;

  std::shared_ptr<Enemy> generateIndifferent() override;

  std::shared_ptr<Enemy> generateOrdinary() override;

  std::shared_ptr<Enemy> generateTraveler() override;

  std::shared_ptr<Enemy> generateReplicator() override;

private:

};

}