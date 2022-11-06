#pragma once
#include <iostream>
#include <string>

using std::string;


namespace superrogue::game_object::character {
class ICharacterClass {
    string __description;
public:
    string get_description() const noexcept;
    ICharacterClass(string description) noexcept;
    virtual ~ICharacterClass() {}
};
};
