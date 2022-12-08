#pragma once
#include "Model/GameModel/const.h"
#include "Model/GameModel/GameObject/Character/Person.h"

namespace GameModel {
/**
 * @brief Person class, which is created according to the description and settings (including the visibility radius)
 * 
 * the field of View is 2 times larger than the standard one
 * 
 */
class Farsighted : public Person {
public:
  Farsighted(std::string name, std::string description, Characteristics characteristics,
             PersonSettings settings,
             Inventory::Inventory inventory =
             Inventory::Inventory(DEFAULT_POTIONS_MAX));
};
}; // namespace superrogue::GameObject::Character
