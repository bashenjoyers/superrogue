#pragma once
#include <iostream>
#include <random>
#include <string>
#include "model/game_object/character/ICharacter.h"
#include "model/game_object/character/class/enemy/IEnemyClass.h"


namespace superrogue::game_object::character {
class IEnemy : public ICharacter {
    superrogue::game_object::character::IEnemyClass __enemy_class;
public:
    std::string get_description() const noexcept override;
    float get_attack_range() const noexcept;
    IEnemy(std::string name, Characteristics characteristics, superrogue::game_object::character::IEnemyClass enemy_class) noexcept;
    superrogue::game_object::character::IEnemyClass get_enemy_class() const noexcept;
    virtual ~IEnemy() {}
};
};
