#pragma once
#include "IPersonClass.h"

namespace GameModel {
/**
 * @brief Person class, which is created according to the description and settings (including the visibility radius)
 * 
 * can see the areas where opponents may be located
 * 
 */
class Wise : public IPersonClass {
public:
  Wise(std::string description, PersonSettings settings = PersonSettings());
};
}; // namespace superrogue::GameObject::Character
