#pragma once
#include "exceptions/exceptions.h"
#include "model/const.h"
#include "model/game_object/item/IItem.h"

namespace superrogue::game_object::item {
class Potion : public IItem {
  int work_time;

public:
  Potion(std::string name, std::string description,
         Characteristics characteristics, int work_time);
  void step() noexcept;
  bool is_work() const noexcept;
};
}; // namespace superrogue::game_object::item
