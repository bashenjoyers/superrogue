#pragma once
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/const.h"
#include "Model/GameModel/GameObject/Item/IItem.h"

namespace GameModel {
class Potion : public IItem {
  int work_time;

public:
  Potion(std::string name, std::string description,
         Characteristics characteristics, int work_time);
  void step() noexcept;
  bool is_work() const noexcept;
};
}; // namespace superrogue::GameObject::Item
