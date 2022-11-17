#pragma once
#include "model/const.h"
#include "model/game_object/character/class/person/IPersonClass.h"

namespace superrogue::game_object::character {
class Farsighted : public IPersonClass {
public:
  Farsighted(std::string description, PersonSettings settings = PersonSettings(
                                          superrogue::DEFAULT_VISIBLE_RADIUS));
};
}; // namespace superrogue::game_object::character
