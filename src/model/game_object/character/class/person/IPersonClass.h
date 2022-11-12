#pragma once
#include "model/game_object/character/class/ICharacterClass.h"
#include "model/const.h"

namespace superrogue::game_object::character {
struct PersonSettings {
    int visible_radius;
    
    PersonSettings(int visible_radius = superrogue::DEFAULT_VISIBLE_RADIUS) : visible_radius(visible_radius) {}
};

class IPersonClass : public ICharacterClass {
    PersonSettings settings;
public:
    PersonSettings get_settings() { return settings; };
    IPersonClass(std::string description, PersonSettings settings) noexcept : 
        ICharacterClass(description), settings(settings) {}
    IPersonClass() {};
    virtual ~IPersonClass() {}
};
};
