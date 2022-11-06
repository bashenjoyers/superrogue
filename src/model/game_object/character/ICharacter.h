#pragma once
#include <iostream>
#include <string>
#include "model/game_object/IGameObject.h"

using std::string;


namespace superrogue::game_object::character {
class ICharacter : public IGameObject {
public:
    virtual string get_description() const noexcept override = 0;
    virtual bool step() = 0;
    virtual bool punch() = 0;
    ICharacter(string name, string description, Characteristics characteristics) noexcept;
    virtual ~ICharacter() {}
};
};
