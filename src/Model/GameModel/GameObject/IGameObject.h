#pragma once
#include "Characteristics.h"
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
  // characteristics of the object
  Characteristics characteristics;

public:
  // getters for properties above
  std::string get_name() const noexcept;
  virtual std::string get_description() const noexcept;
  virtual Characteristics get_characteristics() const noexcept;
  // adds health for object (only used for character so far)
  void add_health(int value) noexcept;
  // takes away health for object (only used for character/enemy so far)
  virtual bool damaged(int value) noexcept; // return is GameObject destroed
  // creates IGameObject by setting basic properties
  IGameObject(std::string name, std::string description,
              Characteristics characteristics);
  IGameObject(){};
  virtual ~IGameObject() {}
};
}; // namespace GameModel
