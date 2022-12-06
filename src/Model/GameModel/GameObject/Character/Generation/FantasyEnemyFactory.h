#pragma once

#include "AbstractEnemyFactory.h"

namespace GameModel::Generation {

class FantasyEnemyFactory : public AbstractEnemyFactory {
public:
    FantasyEnemyFactory(size_t level) : AbstractEnemyFactory(level) {}

    std::shared_ptr<IEnemy> generateAgressive(int guid) override;

    std::shared_ptr<IEnemy> generateCoward(int guid) override;

    std::shared_ptr<IEnemy> generateFlying(int guid) override;

    std::shared_ptr<IEnemy> generateIndifferent(int guid) override;

    std::shared_ptr<IEnemy> generateOrdinary(int guid) override;

    std::shared_ptr<IEnemy> generateTraveler(int guid) override;

    std::shared_ptr<IEnemy> generateReplicator(int guid) override;

private:

};

}