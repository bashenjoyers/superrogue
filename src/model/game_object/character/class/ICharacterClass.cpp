#include "model/game_object/character/class/ICharacterClass.h"

using std::string;

namespace superrogue::game_object::character {
string ICharacterClass::get_description() const noexcept { return description; }

ICharacterClass::ICharacterClass(string description)
    : description(description) {}
}; // namespace superrogue::game_object::character
