#include "model/game_object/character/IEnemy.h"

using std::string;
using superrogue::game_object::character::IEnemyClass;


namespace superrogue::game_object::character {
string IEnemy::get_description() const noexcept {
    return __enemy_class.get_description();
}

IEnemyClass IEnemy::get_enemy_class() const noexcept {    
    return __enemy_class;
}

float IEnemy::get_attack_range() const noexcept {
    return __enemy_class.get_settings().attack_range;
}

IEnemy::IEnemy(string name, Characteristics characteristics, IEnemyClass enemy_class) noexcept :
    ICharacter(name, enemy_class.get_description(), characteristics), __enemy_class(enemy_class) {};
};
