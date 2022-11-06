#pragma once
#include "model/game_object/character/class/ICharacterClass.h"


namespace superrogue::game_object::character {
class IPersonClass : public ICharacterClass {
public:
    IPersonClass(string description) noexcept : ICharacterClass(description) {}
    virtual ~IPersonClass() {}
};
};
