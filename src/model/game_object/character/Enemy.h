#pragma once
#include <iostream>
#include <string>
#include "model/game_object/character/IEnemy.h"
#include "model/game_object/character/class/enemy/IEnemyClass.h"


namespace superrogue::game_object::character {
class Enemy : public IEnemy {
public:
    void step() override;
    void punch() override;
    Enemy(std::string name, Characteristics characteristics, superrogue::game_object::character::IEnemyClass enemy_class, float intellect) noexcept;
    Enemy(const Enemy& enemy) = default;
};
};
