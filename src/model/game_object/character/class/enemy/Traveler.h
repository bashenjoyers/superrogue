#pragma once
#include "model/game_object/character/class/enemy/IEnemyClass.h"


namespace superrogue::game_object::character {
class Traveler : public IEnemyClass {
    superrogue::abstract::Position last_character_position;
public:
    superrogue::abstract::MapEntity get_map_entity() const noexcept override;
    Traveler(std::string description, EnemySettings settings = EnemySettings());
    CharacterAction strategy(std::vector<superrogue::abstract::MapEntityWithPosition>& cells, superrogue::abstract::Position& pos) noexcept;
};
};
