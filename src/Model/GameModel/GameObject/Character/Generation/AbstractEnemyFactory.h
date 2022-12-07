#pragma once

#include "Model/GameModel/GameObject/Character/Enemy.h"

#include <memory>

namespace GameModel::Generation {
class AbstractEnemyFactory {
public:
    AbstractEnemyFactory(size_t level) : level(level) {}
    ~AbstractEnemyFactory() = default;

    virtual std::shared_ptr<Enemy> generateAgressive(int guid) = 0;
    virtual std::shared_ptr<Enemy> generateCoward(int guid) = 0;
    virtual std::shared_ptr<Enemy> generateFlying(int guid) = 0;
    virtual std::shared_ptr<Enemy> generateIndifferent(int guid) = 0;
    virtual std::shared_ptr<Enemy> generateOrdinary(int guid) = 0;
    virtual std::shared_ptr<Enemy> generateTraveler(int guid) = 0;

protected:
    Characteristics generateCharacteristics();
    EnemySettings generateSettings();

    size_t level;
};
}
