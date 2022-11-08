#pragma once
#include "model/game_object/character/class/enemy/IEnemyClass.h"


namespace superrogue::game_object::character {
class Ordinary : public IEnemyClass {
public:
    const int visible_radius = DEFAULT_VISIBLE_RADIUS;
    const bool ignore_walls = false;
    Ordinary(std::string description) noexcept;
    superrogue::game_object::character::CharacterAction strategy(std::vector<superrogue::abstract::Position>& cells, superrogue::abstract::Position& pos, superrogue::abstract::Position& person_pos) noexcept;
};
};
