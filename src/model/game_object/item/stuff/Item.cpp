#include "model/game_object/item/stuff/Item.h"
#include "exceptions/exceptions.h"
#include "model/const.h"
#include <iostream>
#include <string>

namespace superrogue::game_object::item {
Item::Item(std::string name, std::string description,
           Characteristics characteristics, ItemType itemType)
    : IItem(name, description, characteristics), itemType(itemType) {}

ItemType Item::get_item_type() const noexcept { return this->itemType; }
}; // namespace superrogue::game_object::item
