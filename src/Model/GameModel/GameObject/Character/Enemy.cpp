#include "Enemy.h"

using std::string;

namespace GameModel {
void Enemy::step() {}

void Enemy::punch() {}

Enemy::Enemy(int id, string name, Characteristics characteristics,
             IEnemyClass enemy_class)
    : IEnemy(name, characteristics, enemy_class){};

bool Enemy::operator==(const Enemy &other) const noexcept {
  return this->id == other.id;
}

bool Enemy::operator<(const Enemy &other) const noexcept {
  return this->id < other.id;
}
}; // namespace superrogue::GameObject::Character
