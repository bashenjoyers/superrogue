#pragma once
#include "Model/GameModel/const.h"
#include "IPersonClass.h"

namespace GameModel {
class Farsighted : public IPersonClass {
public:
  Farsighted(std::string description, PersonSettings settings = PersonSettings(
                                          DEFAULT_VISIBLE_RADIUS));
};
}; // namespace superrogue::GameObject::Character
