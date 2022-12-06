#pragma once
#include "Characteristics.h"
#include "Model/GameModel/abstract.h"
#include <iostream>
#include <string>

namespace GameModel {
/**
 * @brief base class for any object in the game
 * 
 */
class IGameObject {
  // name of the object
  std::string name;
  // description of the object
  std::string description;

protected:
  // characteristics of the object
  Characteristics characteristics;
  Abstract::Position position;

public:
  // getters for properties above
  virtual std::string get_name() const noexcept;
  virtual std::string get_description() const noexcept;
  virtual Characteristics get_characteristics() const noexcept;
  // adds health for object (only used for character so far)
  virtual void add_health(int value) noexcept;
  // creates IGameObject by setting basic properties
  IGameObject(std::string name, std::string description,
              Characteristics characteristics);
  IGameObject(){};
  virtual ~IGameObject() {}

  Abstract::Position get_position();
  void set_position(Abstract::Position newPos);
};
}; // namespace GameModel
