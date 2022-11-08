#pragma once
#include <iostream>
#include <string>
#include "model/game_object/character/ICharacter.h"
#include "model/game_object/character/class/person/IPersonClass.h"


namespace superrogue::game_object::character {
class IPerson : public ICharacter {
    IPersonClass __person_class;
public:
    std::string get_description() const noexcept override;
    virtual void potion(int potion_i) = 0;
    IPersonClass get_person_class() const noexcept;
    IPerson(std::string name, Characteristics characteristics, IPersonClass person_class) noexcept;
    IPerson() {};
    virtual ~IPerson() {}
};
};
