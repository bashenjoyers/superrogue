#pragma once
#include "Model/GameModel/GameObject/Character/Person.h"

namespace GameModel {
/**
 * @brief Person class, which is created according to the description and settings (including the visibility radius)
 * 
 * can have up to 7 Potions
 * 
 */
class Alchemist : public Person {
public:
  Alchemist(std::string name, std::string description, Characteristics characteristics,
            PersonSettings settings,
            Inventory::Inventory inventory =
            Inventory::Inventory(DEFAULT_POTIONS_MAX));
};
}; // namespace superrogue::GameObject::Character
