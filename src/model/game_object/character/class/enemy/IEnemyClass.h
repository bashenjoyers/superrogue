#pragma once
#include <random>
#include "model/game_object/character/class/ICharacterClass.h"
#include "model/abstract.h"
#include "model/game_object/character/CharacterAction.h"
#include "model/const.h"


namespace superrogue::game_object::character {
struct EnemySettings {
    int visible_radius = DEFAULT_VISIBLE_RADIUS;
    bool ignore_walls = false;
    float intellect = 1;    // [0..1]
    int attack_range = 1;
};

class IEnemyClass : public ICharacterClass {
    EnemySettings __settings;
public:
    EnemySettings get_settings() const noexcept;
    virtual superrogue::abstract::MapEntity get_map_entity() const noexcept { return superrogue::abstract::MapEntity::ENEMY; };
    bool is_vacant(superrogue::abstract::MapEntity map_entity);
    superrogue::game_object::character::CharacterAction default_fight_behavior(int dx, int dy, std::vector<superrogue::game_object::character::CharacterAction>& possible_actions, bool can_punch = true);
    superrogue::game_object::character::CharacterAction strategy(std::vector<superrogue::abstract::MapEntityWithPosition>& cells, superrogue::abstract::Position& pos) noexcept;
    IEnemyClass(std::string description, EnemySettings settings) noexcept;
    virtual ~IEnemyClass() {}
protected:
    superrogue::abstract::Position last_character_position;
};
};
