#pragma once
#include "model/game_object/Characteristics.h"
#include <iostream>
#include <string>

namespace superrogue::game_object {
class IGameObject {
  std::string name;
  std::string description;
  superrogue::Characteristics characteristics;

public:
  std::string get_name() const noexcept;
  virtual std::string get_description() const noexcept;
  virtual superrogue::Characteristics get_characteristics() const noexcept;
  void add_health(int value) noexcept;
  virtual bool damaged(int value) noexcept; // return is game_object destroed
  IGameObject(std::string name, std::string description,
              superrogue::Characteristics characteristics);
  IGameObject(){};
  virtual ~IGameObject() {}
};
}; // namespace superrogue::game_object
