#include "model/game_object/character/class/enemy/Agressive.h"

using std::string;
using std::vector;
using superrogue::abstract::Position;
using superrogue::abstract::MapEntityWithPosition;
using superrogue::game_object::character::CharacterAction;


namespace superrogue::game_object::character {
Agressive::Agressive(string description, EnemySettings settings) noexcept : IEnemyClass(description, settings) {}

CharacterAction Agressive::strategy(vector<MapEntityWithPosition>& cells, Position& pos) noexcept {
    // TODO
    return CharacterAction::WAIT;
}
};
