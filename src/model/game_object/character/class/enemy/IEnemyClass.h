#pragma once
#include "model/game_object/character/class/ICharacterClass.h"
#include "model/abstract.h"
#include "model/game_object/character/CharacterAction.h"
#include "model/const.h"

using std::vector;
using superrogue::abstract::Position;
using superrogue::game_object::character::CharacterAction;


namespace superrogue::game_object::character {
class IEnemyClass : public ICharacterClass {
public:
    int visible_radius;   // TODO(to class, set const)
    bool ignore_walls;
    IEnemyClass(string description) noexcept : ICharacterClass(description), visible_radius(DEFAULT_VISIBLE_RADIUS), ignore_walls(false) {}
    CharacterAction strategy(vector<Position>& cells, Position& pos, Position& person_pos) noexcept;   // TODO(virtual + templates?)
    virtual ~IEnemyClass() {}
};
};
