#include <iostream>
#include <string>
#include "model/game_object/IGameObject.h"

using std::string;
using superrogue::Characteristics;
using std::max;

namespace superrogue::game_object {
IGameObject::IGameObject(string name, string description, Characteristics characteristics) : 
    name(name), description(description), characteristics(characteristics) {}

string IGameObject::get_name() const noexcept {
    return this->name;
}

string IGameObject::get_description() const noexcept {
    return this->description;
}

Characteristics IGameObject::get_characteristics() const noexcept {
    return this->characteristics;
}

void IGameObject::add_health(int value) noexcept {
    characteristics.health += value;
}

bool IGameObject::damaged(int value) noexcept {
    characteristics.health = max(characteristics.health - value, 0);
    return characteristics.health == 0;
}
};
