#include "model/game_object/character/Enemy.h"


namespace superrogue::game_object::character {
bool Enemy::step() {   // TODO
    return true;
}

bool Enemy::punch() {  // TODO
    return true;
}

Enemy::Enemy(string name, Characteristics characteristics, IEnemyClass enemy_class, float intellect) noexcept :
    IEnemy(name, characteristics, enemy_class, intellect) {};
};
