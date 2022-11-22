#pragma once
#include "Model/GameModel/const.h"
#include "IPersonClass.h"

namespace GameModel {
/**
 * @brief Person class, which is created according to the description and settings (including the visibility radius)
 * 
 * the field of View is 2 times larger than the standard one
 * 
 */
class Farsighted : public IPersonClass {
public:
  Farsighted(std::string description, PersonSettings settings = PersonSettings(
                                          DEFAULT_VISIBLE_RADIUS));
};
}; // namespace superrogue::GameObject::Character
