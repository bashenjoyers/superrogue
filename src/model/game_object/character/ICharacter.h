#pragma once
#include <iostream>
#include <string>
#include "model/game_object/IGameObject.h"

using std::string;


namespace superrogue::game_object::character {
class ICharacter : public IGameObject {
public:
    virtual string get_description() const noexcept override = 0;
    virtual void step() = 0;
    virtual void punch() = 0;
    ICharacter(string name, string description, Characteristics characteristics) noexcept;
    ICharacter() {};
    virtual ~ICharacter() {}
};
};
