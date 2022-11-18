#pragma once
#include "IPersonClass.h"

namespace GameModel {
class Lucky : public IPersonClass {
public:
  Lucky(std::string description, PersonSettings settings = PersonSettings());
};
}; // namespace superrogue::GameObject::Character
