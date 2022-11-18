#include "IGameObject.h"
#include <iostream>
#include <string>

using std::max;
using std::string;

namespace GameModel {
IGameObject::IGameObject(string name, string description,
                         Characteristics characteristics)
    : name(name), description(description), characteristics(characteristics) {}

string IGameObject::get_name() const noexcept { return this->name; }

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
}; // namespace GameModel
