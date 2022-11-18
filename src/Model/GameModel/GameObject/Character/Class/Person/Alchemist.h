#pragma once
#include "IPersonClass.h"

namespace GameModel {
class Alchemist : public IPersonClass {
public:
  Alchemist(std::string description,
            PersonSettings settings = PersonSettings());
};
}; // namespace superrogue::GameObject::Character
