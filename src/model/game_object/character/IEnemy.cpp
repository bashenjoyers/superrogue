#include "model/game_object/character/IEnemy.h"


namespace superrogue::game_object::character {
string IEnemy::get_description() const noexcept {
    return __enemy_class.get_description();
}

IEnemyClass IEnemy::get_enemy_class() const noexcept {    
    return __enemy_class;
}

float IEnemy::get_intellect() const noexcept {
    return __intellect;
}

IEnemy::IEnemy(string name, Characteristics characteristics, IEnemyClass enemy_class, float intellect) noexcept :
    ICharacter(name, enemy_class.get_description(), characteristics), __enemy_class(enemy_class), __intellect(intellect) {};
};
