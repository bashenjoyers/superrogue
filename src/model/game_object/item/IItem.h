#pragma once
#include "model/game_object/IGameObject.h"


namespace superrogue::game_object::item {
class IItem : public IGameObject {
public:
    IItem(std::string name, std::string description, Characteristics characteristics);
    IItem(): IGameObject() {};
    virtual ~IItem() {}
};
};
