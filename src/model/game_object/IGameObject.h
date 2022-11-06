#pragma once
#include <iostream>
#include <string>
#include "model/game_object/Characteristics.h"

using std::string;


namespace superrogue::game_object {
class IGameObject {
    string __name;
    string __description;
public:
    string get_name() const noexcept;
    virtual string get_description() const noexcept;
    Characteristics characteristics;
    IGameObject(string name, string description, Characteristics characteristics) noexcept;
    virtual ~IGameObject() {}
};
};
