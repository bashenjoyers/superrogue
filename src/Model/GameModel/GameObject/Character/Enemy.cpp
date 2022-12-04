#include "Enemy.h"

using std::string;

namespace GameModel {
void Enemy::step() {}

void Enemy::punch() {}

Enemy::Enemy(int id, const string &name, Characteristics characteristics,
             std::shared_ptr<IEnemyClass> enemy_class)
    : IEnemy(name, characteristics, enemy_class, id) {};
}; // namespace GameModel
