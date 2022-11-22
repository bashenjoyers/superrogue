#pragma once
#include "IPersonClass.h"

namespace GameModel {
/**
 * @brief Person class, which is created according to the description and settings (including the visibility radius)
 * 
 * can have up to 7 Potions
 * 
 */
class Alchemist : public IPersonClass {
public:
  Alchemist(std::string description,
            PersonSettings settings = PersonSettings());
};
}; // namespace superrogue::GameObject::Character
