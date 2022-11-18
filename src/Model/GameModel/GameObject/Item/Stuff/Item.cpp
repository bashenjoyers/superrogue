#include "Item.h"
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/const.h"
#include <iostream>
#include <string>

namespace GameModel {
Item::Item(std::string name, std::string description,
           Characteristics characteristics, ItemType itemType)
    : IItem(name, description, characteristics), itemType(itemType) {}

ItemType Item::get_item_type() const noexcept { return this->itemType; }
}; // namespace GameModel
