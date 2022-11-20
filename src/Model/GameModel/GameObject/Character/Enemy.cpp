#include "Enemy.h"

using std::string;

namespace GameModel {
void Enemy::step() {}

void Enemy::punch() {}

Enemy::Enemy(int id, string name, Characteristics characteristics,
             std::shared_ptr<IEnemyClass> enemy_class)
    : IEnemy(name, characteristics, enemy_class), id(id) {};

bool Enemy::operator==(const Enemy &other) const noexcept {
  return this->id == other.id;
}

bool Enemy::operator<(const Enemy &other) const noexcept {
  return this->id < other.id;
}
}; // namespace GameModel
