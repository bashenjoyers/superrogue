#include "Item.h"
#include <string>

namespace GameModel {
Item::Item(std::string name, std::string description,
           Characteristics characteristics, ItemType itemType)
    : IItem(name, description, characteristics), itemType(itemType) {}

ItemType Item::get_item_type() const noexcept { return this->itemType; }

Abstract::MapEntity Item::getMapEntity() {
    return Abstract::MapEntity::ITEM;
}
}; // namespace GameModel
