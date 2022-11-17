#include "model/game_object/item/potions/Potion.h"
#include "exceptions/exceptions.h"
#include "model/const.h"
#include <iostream>
#include <string>

using superrogue::exception::GameObjectException;

namespace superrogue::game_object::item {
Potion::Potion(std::string name, std::string description,
               Characteristics characteristics,
               int work_time = DEFAULT_POTION_WORK_TIME)
    : IItem(name, description, characteristics), work_time(work_time) {
  if (work_time < 0) {
    throw GameObjectException(std::string("word_time should be more than 0"));
  }
}

void Potion::step() noexcept {
  if (work_time > 0)
    work_time--;
}

bool Potion::is_work() const noexcept { return work_time != 0; }
}; // namespace superrogue::game_object::item
