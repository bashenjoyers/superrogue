#pragma once
#include "Model/GameModel/const.h"
#include "Model/GameModel/GameObject/Character/Class/ICharacterClass.h"

#include <string>
namespace GameModel {
/**
 * @brief Person settings
 * 
 */
struct PersonSettings {
  // character visibility range
  int visible_radius;
  // is person can 
  bool visible_enemy;
  // enemies visibility range for user: radius * other_visible_k
  float other_visible_k;
  // creates settings by radius
  PersonSettings(int visible_radius = DEFAULT_VISIBLE_RADIUS, float other_visible_k = 1, bool visible_enemy=false)
      : visible_radius(visible_radius), other_visible_k(other_visible_k) {}
};

class IPersonClass : public ICharacterClass {
  PersonSettings settings;

public:
  PersonSettings get_settings() { return settings; };
  IPersonClass(std::string description, PersonSettings settings)
      : ICharacterClass(description), settings(settings) {}
  IPersonClass(){};
  virtual ~IPersonClass() {}
};
}; // namespace superrogue::GameObject::Character
