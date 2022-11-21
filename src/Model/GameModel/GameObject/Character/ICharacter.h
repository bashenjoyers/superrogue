#pragma once
#include "Model/GameModel/GameObject/IGameObject.h"
#include <iostream>
#include <string>

namespace GameModel {
/**
 * @brief interface for any character
 * 
 */
class ICharacter : public IGameObject {
public:
  // returns an overridden empty description (nothing is known about the abstract character)
  virtual std::string get_description() const noexcept override { return ""; };
  // determines the action on step
  virtual void step(){};
  // determines the action on punch
  virtual void punch(){};
  // creates an instance according to the standard properties of the object
  ICharacter(std::string name, std::string description,
             Characteristics characteristics);
  ICharacter(){};
  virtual ~ICharacter() {}
};
}; // namespace GameModel
