#pragma once
#include <iostream>
#include <string>
#include "model/game_object/character/IEnemy.h"

using std::string;


namespace superrogue::game_object::character {
class Enemy : public IEnemy {
public:
    bool step() override;
    bool punch() override;
    Enemy(string name, Characteristics characteristics, IEnemyClass enemy_class, float intellect) noexcept;
};
};
