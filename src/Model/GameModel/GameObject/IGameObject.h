#pragma once
#include "Characteristics.h"
#include <iostream>
#include <string>

namespace GameModel {
class IGameObject {
  std::string name;
  std::string description;
  Characteristics characteristics;

public:
  std::string get_name() const noexcept;
  virtual std::string get_description() const noexcept;
  virtual Characteristics get_characteristics() const noexcept;
  void add_health(int value) noexcept;
  virtual bool damaged(int value) noexcept; // return is GameObject destroed
  IGameObject(std::string name, std::string description,
              Characteristics characteristics);
  IGameObject(){};
  virtual ~IGameObject() {}
};
}; // namespace GameModel
