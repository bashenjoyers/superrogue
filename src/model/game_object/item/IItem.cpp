#include <iostream>
#include <string>
#include "model/game_object/item/IItem.h"


superrogue::game_object::item::IItem::IItem(std::string name, std::string description, Characteristics characteristics) : 
    IGameObject(name, description, characteristics) {}
