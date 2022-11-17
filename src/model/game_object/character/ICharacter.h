#pragma once
#include <iostream>
#include <string>
#include "model/game_object/IGameObject.h"


namespace superrogue::game_object::character {
class ICharacter : public IGameObject {
public:
    virtual std::string get_description() const noexcept override { return ""; };
    virtual void step() {};
    virtual void punch() {};
    ICharacter(std::string name, std::string description, Characteristics characteristics);
    ICharacter() {};
    virtual ~ICharacter() {}
};
};
