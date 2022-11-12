#include "model/game_object/character/class/person/Lucky.h"

using std::string;


namespace superrogue::game_object::character {
Lucky::Lucky(string description, PersonSettings settings) noexcept : IPersonClass(description, settings) {}
};
