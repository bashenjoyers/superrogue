#pragma once

#include "AbstractEnemyFactory.h"

namespace GameModel::Generation {

class FantasyEnemyFactory : public AbstractEnemyFactory {
public:
    FantasyEnemyFactory(size_t level) : AbstractEnemyFactory(level) {}

    std::shared_ptr<IEnemy> generateAgressive(int guid, const Abstract::Position& pos) override;

    std::shared_ptr<IEnemy> generateCoward(int guid, const Abstract::Position& pos) override;

    std::shared_ptr<IEnemy> generateFlying(int guid, const Abstract::Position& pos) override;

    std::shared_ptr<IEnemy> generateIndifferent(int guid, const Abstract::Position& pos) override;

    std::shared_ptr<IEnemy> generateOrdinary(int guid, const Abstract::Position& pos) override;

    std::shared_ptr<IEnemy> generateTraveler(int guid, const Abstract::Position& pos) override;

private:

};

}