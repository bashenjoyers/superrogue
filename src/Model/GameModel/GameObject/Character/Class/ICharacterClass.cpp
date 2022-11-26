#include "ICharacterClass.h"

using std::string;

namespace GameModel {
string ICharacterClass::get_description() const noexcept { return description; }

ICharacterClass::ICharacterClass(string description)
    : description(description) {}
}; // namespace GameModel
