#pragma once
#include "model/game_object/IGameObject.h"
#include <iostream>
#include <string>

namespace superrogue::game_object::character {
class ICharacter : public IGameObject {
public:
  virtual std::string get_description() const noexcept override { return ""; };
  virtual void step(){};
  virtual void punch(){};
  ICharacter(std::string name, std::string description,
             Characteristics characteristics);
  ICharacter(){};
  virtual ~ICharacter() {}
};
}; // namespace superrogue::game_object::character
