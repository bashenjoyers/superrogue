#include "model/game_object/character/IPerson.h"


namespace superrogue::game_object::character {
string IPerson::get_description() const noexcept {
    return __person_class.get_description();
}

IPersonClass IPerson::get_person_class() const noexcept {    
    return __person_class;
}

IPerson::IPerson(string name, Characteristics characteristics, IPersonClass person_class) noexcept :
    ICharacter(name, person_class.get_description(), characteristics), __person_class(person_class) {};
};
