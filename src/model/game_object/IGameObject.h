#pragma once
#include <iostream>
#include <string>
#include "model/game_object/Characteristics.h"


namespace superrogue::game_object {
class IGameObject {
    std::string __name;
    std::string __description;
public:
    std::string get_name() const noexcept;
    virtual std::string get_description() const noexcept;
    Characteristics characteristics;
    IGameObject(std::string name, std::string description, Characteristics characteristics) noexcept;
    IGameObject() {};
    virtual ~IGameObject() {}
};
};
