#pragma once
#include "model/game_object/IGameObject.h"


namespace superrogue::game_object::item {
class IItem : public IGameObject {
public:
    IItem(string name, string description, Characteristics characteristics) noexcept;
    virtual ~IItem() {}
};
};
