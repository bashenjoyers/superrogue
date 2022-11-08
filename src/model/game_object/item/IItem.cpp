#include <iostream>
#include <string>
#include "model/game_object/item/IItem.h"


superrogue::game_object::item::IItem::IItem(std::string name, std::string description, Characteristics characteristics) noexcept : 
    IGameObject(name, description, characteristics) {}
