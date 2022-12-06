#pragma once
#include "IEnemyClass.h"

namespace GameModel {
/**
 * @brief Enemy class, which is created according to the description and settings
 *
 * randomly replicates on nearest cell
 *
 */
    class Replicator : public IEnemyClass {
        // the last visible position of the character, used if he is this character is smart enough (character characteristic)
        Abstract::Position last_character_position;
        double replication_prob;

    public:
        // returns how to display it on the map (can hide its class if smart enough (character characteristic))
        Abstract::MapEntity get_map_entity() const noexcept override;
        Replicator(std::string description, EnemySettings settings = EnemySettings());
        // returns the strategy for the current class
        CharacterAction strategy(std::vector<Abstract::MapEntityWithPosition> &cells,
                                 const Abstract::Position &pos) noexcept override;
        double get_replication_probability();
    };
}; // namespace GameModel
