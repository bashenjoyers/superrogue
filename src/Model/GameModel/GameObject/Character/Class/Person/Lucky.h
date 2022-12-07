#pragma once
#include "IPersonClass.h"

namespace GameModel {
/**
 * @brief Person class, which is created according to the description and settings (including the visibility radius)
 * 
 * has luck >= 0.9
 * 
 */
class Lucky : public IPersonClass {
public:
  Lucky(std::string description, PersonSettings settings = PersonSettings());
};
}; // namespace superrogue::GameObject::Character
