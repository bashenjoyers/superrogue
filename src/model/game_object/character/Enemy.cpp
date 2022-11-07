#include "model/game_object/character/Enemy.h"


namespace superrogue::game_object::character {
void Enemy::step() {   // TODO

}

void Enemy::punch() {  // TODO

}

Enemy::Enemy(string name, Characteristics characteristics, IEnemyClass enemy_class, float intellect) noexcept :
    IEnemy(name, characteristics, enemy_class, intellect) {};
};
