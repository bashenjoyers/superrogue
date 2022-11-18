#pragma once
#include "Model/GameModel/const.h"
#include "Model/GameModel/GameObject/Character/Class/ICharacterClass.h"

#include <string>
namespace GameModel {
struct PersonSettings {
  int visible_radius;
  PersonSettings(int visible_radius = DEFAULT_VISIBLE_RADIUS)
      : visible_radius(visible_radius) {}
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
