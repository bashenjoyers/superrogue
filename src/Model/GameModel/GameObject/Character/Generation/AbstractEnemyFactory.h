#pragma once

#include "Model/GameModel/GameObject/Character/IEnemy.h"

#include <memory>

namespace GameModel::Generation {
class AbstractEnemyFactory {
public:
    AbstractEnemyFactory(size_t level) : level(level) {}
    ~AbstractEnemyFactory() = default;

    virtual std::shared_ptr<IEnemy> generateAgressive(int guid) = 0;
    virtual std::shared_ptr<IEnemy> generateCoward(int guid) = 0;
    virtual std::shared_ptr<IEnemy> generateFlying(int guid) = 0;
    virtual std::shared_ptr<IEnemy> generateIndifferent(int guid) = 0;
    virtual std::shared_ptr<IEnemy> generateOrdinary(int guid) = 0;
    virtual std::shared_ptr<IEnemy> generateTraveler(int guid) = 0;
    virtual std::shared_ptr<IEnemy> generateRedReplicator(int guid) = 0;
  	virtual std::shared_ptr<IEnemy> generateGreenReplicator(int guid) = 0;


protected:
    Characteristics generateCharacteristics();
    EnemySettings generateSettings();

    size_t level;
};
}
