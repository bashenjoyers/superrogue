#pragma once
#include "model/const.h"
#include "model/game_object/character/class/ICharacterClass.h"

namespace superrogue::game_object::character {
struct PersonSettings {
  int visible_radius;
  PersonSettings(int visible_radius = superrogue::DEFAULT_VISIBLE_RADIUS)
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
}; // namespace superrogue::game_object::character
