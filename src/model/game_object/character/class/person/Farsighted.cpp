#include "model/game_object/character/class/person/Farsighted.h"

using std::string;

namespace superrogue::game_object::character {
Farsighted::Farsighted(string description, PersonSettings settings)
    : IPersonClass(description, settings) {}
}; // namespace superrogue::game_object::character
