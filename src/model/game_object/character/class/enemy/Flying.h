#pragma once
#include "model/game_object/character/class/enemy/IEnemyClass.h"


namespace superrogue::game_object::character {
class Flying : public IEnemyClass {
    superrogue::abstract::Position last_character_position;
public:
    const int visible_radius = DEFAULT_VISIBLE_RADIUS;
    const bool ignore_walls = false;    // FIXME
    superrogue::abstract::MapEntity get_map_entity() const noexcept override;
    Flying(std::string description, EnemySettings settings = EnemySettings()) noexcept;
    CharacterAction strategy(std::vector<superrogue::abstract::MapEntityWithPosition>& cells, superrogue::abstract::Position& pos) noexcept;
};
};
