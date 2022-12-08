#pragma once
#include "Model/GameModel/GameObject/Character/Person.h"

namespace GameModel {
/**
 * @brief Person class, which is created according to the description and settings (including the visibility radius)
 * 
 * has luck >= 0.9
 * 
 */
class Lucky : public Person {
public:
  Lucky(std::string name);
};
}; // namespace superrogue::GameObject::Character
