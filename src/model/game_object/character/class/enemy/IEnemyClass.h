#pragma once
#include "model/game_object/character/class/ICharacterClass.h"
#include "model/abstract.h"
#include "model/game_object/character/CharacterAction.h"
#include "model/const.h"


namespace superrogue::game_object::character {
struct EnemySettings {
    int visible_radius = DEFAULT_VISIBLE_RADIUS;
    bool ignore_walls = false;
    float intellect = 1;
};

class IEnemyClass : public ICharacterClass {
    EnemySettings __settings;
public:
    EnemySettings get_settings() { return __settings; };
    IEnemyClass(std::string description, EnemySettings settings) noexcept : ICharacterClass(description), __settings(settings) {}
    superrogue::game_object::character::CharacterAction strategy(std::vector<superrogue::abstract::MapEntityWithPosition>& cells, superrogue::abstract::Position& pos) noexcept { return superrogue::game_object::character::CharacterAction::WAIT; };
    virtual ~IEnemyClass() {}
};
};
