#include <iostream>
#include <string>
#include "model/game_object/IGameObject.h"


namespace superrogue::game_object {
IGameObject::IGameObject(string name, string description, Characteristics characteristics) noexcept : 
    __name(name), __description(description), characteristics(characteristics) {}


string IGameObject::get_name() const noexcept {
    return this->__name;
}


string IGameObject::get_description() const noexcept {
    return this->__description;
}
};
