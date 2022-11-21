#pragma once
#include "IPersonClass.h"

namespace GameModel {
/**
 * @brief Person class, which is created according to the description and settings (including the visibility radius)
 * 
 * the field of View of opponents is 2 times smaller for the Character
 * 
 */
class Secretive : public IPersonClass {
public:
  Secretive(std::string description,
            PersonSettings settings = PersonSettings());
};
}; // namespace superrogue::GameObject::Character
