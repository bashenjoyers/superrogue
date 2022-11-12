#pragma once
#include "model/game_object/character/class/person/IPersonClass.h"


namespace superrogue::game_object::character {
class Wise : public IPersonClass {
public:
    Wise(std::string description, PersonSettings settings=PersonSettings()) noexcept;
};
};
