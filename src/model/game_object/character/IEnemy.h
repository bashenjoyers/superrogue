#pragma once
#include <iostream>
#include <string>
#include "model/game_object/character/ICharacter.h"
#include "model/game_object/character/class/enemy/IEnemyClass.h"

using std::string;


namespace superrogue::game_object::character {
class IEnemy : public ICharacter {
    IEnemyClass __enemy_class;
    float __intellect;
public:
    string get_description() const noexcept override;
    float get_intellect() const noexcept;
    IEnemy(string name, Characteristics characteristics, IEnemyClass enemy_class, float intellect) noexcept;
    IEnemyClass get_enemy_class() const noexcept;
    virtual ~IEnemy() {}
};
};
