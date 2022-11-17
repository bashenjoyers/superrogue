#pragma once
#include <iostream>
#include <string>
#include "model/game_object/character/ICharacter.h"
#include "model/game_object/character/class/person/IPersonClass.h"


namespace superrogue::game_object::character {
class IPerson : public ICharacter {
    IPersonClass person_class;
public:
    std::string get_description() const noexcept override;
    virtual void potion(int potion_i) = 0;
    IPersonClass get_person_class() const noexcept;
    IPerson(std::string name, superrogue::Characteristics characteristics, superrogue::game_object::character::IPersonClass person_class);
    IPerson() {};
    virtual ~IPerson() {}
};
};
