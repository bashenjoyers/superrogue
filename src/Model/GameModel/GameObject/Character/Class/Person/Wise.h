#pragma once
#include "IPersonClass.h"

namespace GameModel {
class Wise : public IPersonClass {
public:
  Wise(std::string description, PersonSettings settings = PersonSettings());
};
}; // namespace superrogue::GameObject::Character
