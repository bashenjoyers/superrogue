#include "model/game_object/character/Enemy.h"

using std::string;
using superrogue::game_object::character::IEnemyClass;


namespace superrogue::game_object::character {
void Enemy::step() {}

void Enemy::punch() {}

Enemy::Enemy(int id, string name, Characteristics characteristics, IEnemyClass enemy_class, float intellect, int attack_range) noexcept :
    IEnemy(name, characteristics, enemy_class, intellect, attack_range) {};

bool Enemy::operator==(const Enemy& other) const noexcept {
    return this->id == other.id;
}

bool Enemy::operator<(const Enemy& other) const noexcept {
    return this->id < other.id;
}
};
