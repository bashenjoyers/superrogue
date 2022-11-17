#include "model/game_object/character/class/person/Alchemist.h"

using std::string;

namespace superrogue::game_object::character {
Alchemist::Alchemist(string description, PersonSettings settings)
    : IPersonClass(description, settings) {}
}; // namespace superrogue::game_object::character
