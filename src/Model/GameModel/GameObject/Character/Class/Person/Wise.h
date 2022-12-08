#pragma once
#include "Model/GameModel/GameObject/Character/Person.h"

namespace GameModel {
/**
 * @brief Person class, which is created according to the description and settings (including the visibility radius)
 * 
 * can see the areas where opponents may be located
 * 
 */
class Wise : public Person {
public:
  Wise(std::string name, std::string description, Characteristics characteristics,
       PersonSettings settings,
       Inventory::Inventory inventory =
       Inventory::Inventory(DEFAULT_POTIONS_MAX));
};
}; // namespace superrogue::GameObject::Character
