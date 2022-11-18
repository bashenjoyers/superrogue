#pragma once
#include "IPersonClass.h"

namespace GameModel {
class Secretive : public IPersonClass {
public:
  Secretive(std::string description,
            PersonSettings settings = PersonSettings());
};
}; // namespace superrogue::GameObject::Character
