#pragma once
#include <random>
#include <time.h>
#include "model/game_object/character/class/ICharacterClass.h"
#include "model/abstract.h"
#include "model/game_object/character/CharacterAction.h"
#include "model/const.h"


namespace superrogue::game_object::character {
struct EnemySettings {
    int visible_radius = DEFAULT_VISIBLE_RADIUS;
    bool ignore_walls = false;
    float intellect = 1;
    int attack_range = 1;
};

class IEnemyClass : public ICharacterClass {
    EnemySettings __settings;
public:
    std::mt19937::result_type rand_seed = time(0);
    EnemySettings get_settings() const noexcept { return __settings; };
    IEnemyClass(std::string description, EnemySettings settings) noexcept : ICharacterClass(description), __settings(settings) {}
    superrogue::game_object::character::CharacterAction strategy(std::vector<superrogue::abstract::MapEntityWithPosition>& cells, superrogue::abstract::Position& pos) noexcept { return superrogue::game_object::character::CharacterAction::WAIT; };
    virtual ~IEnemyClass() {}
};
};
