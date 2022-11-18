#pragma once
#include <iostream>
#include <string>

namespace GameModel {
class ICharacterClass {
  std::string description;

public:
  std::string get_description() const noexcept;
  ICharacterClass(std::string description = "");
  virtual ~ICharacterClass() {}
};
}; // namespace GameModel
