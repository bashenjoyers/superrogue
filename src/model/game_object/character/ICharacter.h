#pragma once
#include <iostream>
#include <string>
#include "model/game_object/IGameObject.h"


namespace superrogue::game_object::character {
class ICharacter : public IGameObject {
public:
    virtual std::string get_description() const noexcept override = 0;
    virtual void step() = 0;
    virtual void punch() = 0;
    ICharacter(std::string name, std::string description, Characteristics characteristics) noexcept;
    ICharacter() {};
    virtual ~ICharacter() {}
};
};
