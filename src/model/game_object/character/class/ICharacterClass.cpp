#include "model/game_object/character/class/ICharacterClass.h"


namespace superrogue::game_object::character {
string ICharacterClass::get_description() const noexcept {
    return __description;
}

ICharacterClass::ICharacterClass(string description) noexcept : __description(description) {}
};
