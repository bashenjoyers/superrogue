#pragma once
#include <iostream>
#include <string>


namespace superrogue::game_object::character {
class ICharacterClass {
    std::string description;
public:
    std::string get_description() const noexcept;
    ICharacterClass(std::string description = "");
    virtual ~ICharacterClass() {}
};
};
