#include <iostream>
#include <string>
#include "model/game_object/item/stuff/Item.h"
#include "model/const.h"
#include "exceptions/exceptions.h"


namespace superrogue::game_object::item {
Item::Item(string name, string description, Characteristics characteristics, ItemType itemType) noexcept : 
    IItem(name, description, characteristics), itemType(itemType) {}


ItemType Item::get_item_type() const noexcept {
    return this->itemType;
}
};
