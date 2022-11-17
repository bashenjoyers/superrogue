#pragma once
#include "exceptions/exceptions.h"
#include "model/const.h"
#include "model/game_object/item/IItem.h"

namespace superrogue::game_object::item {
enum class ItemType { HELMET, ARMOR, BOOTS, WEAPON_MELEE, WEAPON_DISTANT };

class Item : public IItem {
  ItemType itemType;

public:
  Item(std::string name, std::string description,
       Characteristics characteristics, ItemType itemType);
  ItemType get_item_type() const noexcept;
  Item &operator=(const Item &other) = default;
};
}; // namespace superrogue::game_object::item
