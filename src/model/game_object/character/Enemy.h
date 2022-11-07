#pragma once
#include <iostream>
#include <string>
#include "model/game_object/character/IEnemy.h"
#include "model/game_object/character/class/enemy/IEnemyClass.h"

using std::string;
using superrogue::game_object::character::IEnemyClass;


namespace superrogue::game_object::character {
class Enemy : public IEnemy {
public:
    void step() override;
    void punch() override;
    Enemy(string name, Characteristics characteristics, IEnemyClass enemy_class, float intellect) noexcept;
};
};
