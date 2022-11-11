#include "model/game_object/character/class/enemy/Ordinary.h"

using std::string;
using std::vector;
using superrogue::abstract::Position;
using superrogue::abstract::MapEntityWithPosition;
using superrogue::game_object::character::CharacterAction;


namespace superrogue::game_object::character {
Ordinary::Ordinary(string description, EnemySettings settings) noexcept : IEnemyClass(description, settings) {}

CharacterAction Ordinary::strategy(vector<MapEntityWithPosition>& cells, Position& pos) noexcept {
    return CharacterAction::WAIT;
}
};
