#pragma once
#include "model/game_object/character/class/person/IPersonClass.h"


namespace superrogue::game_object::character {
class Lucky : public IPersonClass {
public:
    Lucky(std::string description, PersonSettings settings=PersonSettings());
};
};
