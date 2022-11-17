#pragma once
#include "model/game_object/character/class/person/IPersonClass.h"


namespace superrogue::game_object::character {
class Secretive : public IPersonClass {
public:
    Secretive(std::string description, PersonSettings settings=PersonSettings());
};
};
