#include "model/game_object/character/class/enemy/Ordinary.h"

using std::string;
using std::vector;
using superrogue::abstract::Position;
using superrogue::game_object::character::CharacterAction;


namespace superrogue::game_object::character {
Ordinary::Ordinary(string description) noexcept : IEnemyClass(description) {}

CharacterAction Ordinary::strategy(vector<Position>& cells, Position& pos, Position& person_pos) noexcept {
    return CharacterAction::POTION;
}
};
