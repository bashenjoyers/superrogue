#include "model/game_object/character/Enemy.h"

using std::string;
using superrogue::game_object::character::IEnemyClass;


namespace superrogue::game_object::character {
void Enemy::step() {}

void Enemy::punch() {}

Enemy::Enemy(string name, Characteristics characteristics, IEnemyClass enemy_class, float intellect, int attack_range) noexcept :
    IEnemy(name, characteristics, enemy_class, intellect, attack_range) {};
};
