#pragma once
#include <iostream>
#include <string>

namespace GameModel {
/**
 * @brief interface for character 'class' (type)
 * 
 */
class ICharacterClass {
  // class descriptions (used when describing a character)
  std::string description;

public:
  // gives a description of the character
  std::string get_description() const noexcept;
  // creates a class by description
  ICharacterClass(std::string description = "");
  virtual ~ICharacterClass() {}
};
}; // namespace GameModel
