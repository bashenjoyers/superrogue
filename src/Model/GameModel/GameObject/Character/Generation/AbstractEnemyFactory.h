#pragma once

#include "Model/GameModel/GameObject/Character/IEnemy.h"

#include <memory>

namespace GameModel::Generation {
class AbstractEnemyFactory {
public:
    AbstractEnemyFactory(size_t level) : level(level) {}
    ~AbstractEnemyFactory() = default;

    virtual std::shared_ptr<IEnemy> generateAgressive(int guid, const Abstract::Position& pos) = 0;
    virtual std::shared_ptr<IEnemy> generateCoward(int guid, const Abstract::Position& pos) = 0;
    virtual std::shared_ptr<IEnemy> generateFlying(int guid, const Abstract::Position& pos) = 0;
    virtual std::shared_ptr<IEnemy> generateIndifferent(int guid, const Abstract::Position& pos) = 0;
    virtual std::shared_ptr<IEnemy> generateOrdinary(int guid, const Abstract::Position& pos) = 0;
    virtual std::shared_ptr<IEnemy> generateTraveler(int guid, const Abstract::Position& pos) = 0;

protected:
    Characteristics generateCharacteristics();
    EnemySettings generateSettings(Abstract::EnemyClass enemy_class, const Abstract::Position& pos);

    size_t level;
};
}
