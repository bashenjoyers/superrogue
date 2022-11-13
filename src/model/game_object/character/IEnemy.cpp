#include "model/game_object/character/IEnemy.h"
#include "model/game_object/character/class/enemy/Indifferent.h"

using std::string;
using superrogue::game_object::character::IEnemyClass;
using superrogue::game_object::character::Indifferent;


namespace superrogue::game_object::character {
string IEnemy::get_description() const noexcept {
    return __enemy_class.get_description();
}

IEnemyClass IEnemy::get_enemy_class() const noexcept {    
    return __enemy_class;
}

void IEnemy::disturb() {
    if (typeid(__enemy_class) == typeid(Indifferent)) {
        dynamic_cast<Indifferent*>(&__enemy_class)->disturb();
    }
}

float IEnemy::get_attack_range() const noexcept {
    return __enemy_class.get_settings().attack_range;
}

IEnemy::IEnemy(string name, Characteristics characteristics, IEnemyClass enemy_class) noexcept :
    ICharacter(name, enemy_class.get_description(), characteristics), __enemy_class(enemy_class) {};

bool IEnemy::damaged(int value) {
    disturb();
    return ICharacter::damaged(value);
}
};
