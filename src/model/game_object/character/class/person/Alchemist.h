#pragma once
#include "model/game_object/character/class/person/IPersonClass.h"


namespace superrogue::game_object::character {
class Alchemist : public IPersonClass {
public:
    Alchemist(std::string description, PersonSettings settings=PersonSettings()) noexcept;
};
};
