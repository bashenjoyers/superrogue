#pragma once
#include "model/game_object/character/class/ICharacterClass.h"
#include "model/abstract.h"
#include "model/game_object/character/CharacterAction.h"
#include "model/const.h"


namespace superrogue::game_object::character {
class IEnemyClass : public ICharacterClass {
public:
    int visible_radius;   // TODO(to class, set const)
    bool ignore_walls;
    IEnemyClass(std::string description) noexcept : ICharacterClass(description), visible_radius(DEFAULT_VISIBLE_RADIUS), ignore_walls(false) {}
    superrogue::game_object::character::CharacterAction strategy(std::vector<superrogue::abstract::Position>& cells, superrogue::abstract::Position& pos, superrogue::abstract::Position& person_pos) noexcept { return superrogue::game_object::character::CharacterAction::POTION; };   // TODO(virtual + templates?)
    virtual ~IEnemyClass() {}
};
};
