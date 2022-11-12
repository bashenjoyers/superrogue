#pragma once
#include <iostream>
#include <string>


namespace superrogue::game_object::character {
class ICharacterClass {
    std::string __description;
public:
    std::string get_description() const noexcept;
    ICharacterClass(std::string description = "") noexcept;
    virtual ~ICharacterClass() {}
};
};
