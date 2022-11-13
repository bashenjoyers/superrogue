#pragma once
#include "model/game_object/character/class/enemy/IEnemyClass.h"


namespace superrogue::game_object::character {
class Indifferent : public IEnemyClass {
    superrogue::abstract::Position last_character_position;
    bool disturbed = false;
public:
    const int visible_radius = DEFAULT_VISIBLE_RADIUS;
    const bool ignore_walls = false;
    void disturb() noexcept;
    superrogue::abstract::MapEntity get_map_entity() const noexcept override;
    Indifferent(std::string description, EnemySettings settings = EnemySettings()) noexcept;
    CharacterAction strategy(std::vector<superrogue::abstract::MapEntityWithPosition>& cells, superrogue::abstract::Position& pos) noexcept;
};
};
