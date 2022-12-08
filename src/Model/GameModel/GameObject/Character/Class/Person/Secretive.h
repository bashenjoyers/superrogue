#pragma once
#include "Model/GameModel/GameObject/Character/Person.h"

namespace GameModel {
/**
 * @brief Person class, which is created according to the description and settings (including the visibility radius)
 * 
 * the field of View of opponents is 2 times smaller for the Character
 * 
 */
class Secretive : public Person {
public:
  Secretive(std::string name);
};
}; // namespace superrogue::GameObject::Character
