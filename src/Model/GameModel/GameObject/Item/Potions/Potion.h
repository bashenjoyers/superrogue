#pragma once
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/GameObject/Item/IItem.h"
#include "Model/GameModel/const.h"

namespace GameModel {
class Potion : public IItem {
  // potion work time. Decreases with each turn after cast
  int work_time;

public:
  /**
   * @brief Construct a new Potion with all the properties inherent in each object and work time
   * 
   */
  Potion(std::string name, std::string description,
         Characteristics characteristics, int work_time);
  // called before each action of the character, reduces the duration of the potion by 1
  void step() noexcept;
  // returns whether the potion is still working (time has not expired)
  bool is_work() const noexcept;
};
}; // namespace GameModel
