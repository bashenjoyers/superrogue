#pragma once
#include "model/game_object/character/class/person/IPersonClass.h"
#include "model/const.h"


namespace superrogue::game_object::character {
class Farsighted : public IPersonClass {
public:
    Farsighted(std::string description, PersonSettings settings=PersonSettings(superrogue::DEFAULT_VISIBLE_RADIUS)) noexcept;
};
};
