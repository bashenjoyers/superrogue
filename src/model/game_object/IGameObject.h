#pragma once
#include <iostream>
#include <string>
#include "model/game_object/Characteristics.h"


namespace superrogue::game_object {
class IGameObject {
    std::string __name;
    std::string __description;
    superrogue::Characteristics characteristics;
public:
    std::string get_name() const noexcept;
    virtual std::string get_description() const noexcept;
    virtual superrogue::Characteristics get_characteristics() const noexcept;
    bool damaged(int value);    // return is game_object destroed
    IGameObject(std::string name, std::string description, superrogue::Characteristics characteristics) noexcept;
    IGameObject() {};
    virtual ~IGameObject() {}
};
};
