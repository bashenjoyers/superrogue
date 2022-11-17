#include "model/game_object/item/IItem.h"
#include <iostream>
#include <string>

superrogue::game_object::item::IItem::IItem(std::string name,
                                            std::string description,
                                            Characteristics characteristics)
    : IGameObject(name, description, characteristics) {}
