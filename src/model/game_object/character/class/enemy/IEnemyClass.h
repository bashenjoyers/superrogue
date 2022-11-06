#pragma once
#include "model/game_object/character/class/ICharacterClass.h"


namespace superrogue::game_object::character {
class IEnemyClass : public ICharacterClass {
public:
    IEnemyClass(string description) noexcept : ICharacterClass(description) {}
    void strategy() noexcept;   // TODO(virtual + templates?)
    virtual ~IEnemyClass() {}
};
};
