#pragma once
#include "model/game_object/character/class/enemy/IEnemyClass.h"


namespace superrogue::game_object::character {
class Ordinary : public IEnemyClass {
public:
    Ordinary(string description) noexcept;
    void strategy() noexcept;
};
};
