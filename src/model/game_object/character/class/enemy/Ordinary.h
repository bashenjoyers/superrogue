#pragma once
#include "model/game_object/character/class/enemy/IEnemyClass.h"


namespace superrogue::game_object::character {
class Ordinary : public IEnemyClass {
public:
    const int visible_radius = DEFAULT_VISIBLE_RADIUS;
    const bool ignore_walls = false;
    Ordinary(string description) noexcept;
    CharacterAction strategy(vector<Position>& cells, Position& pos, Position& person_pos) noexcept;
};
};
