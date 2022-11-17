#pragma once
#include <iostream>
#include <string>
#include "model/game_object/character/IEnemy.h"
#include "model/game_object/character/class/enemy/IEnemyClass.h"


namespace superrogue::game_object::character {
class Enemy : public IEnemy {
    int id;
public:
    void step() override;
    void punch() override;
    bool operator==(const Enemy& other) const noexcept;
    bool operator<(const Enemy& other) const noexcept;
    Enemy(int id, std::string name, Characteristics characteristics, superrogue::game_object::character::IEnemyClass enemy_class);
    Enemy(const Enemy& enemy) = default;
};
};
