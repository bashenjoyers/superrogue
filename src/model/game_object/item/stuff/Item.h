#pragma once
#include "model/game_object/item/IItem.h"
#include "model/const.h"
#include "exceptions/exceptions.h"


namespace superrogue::game_object::item {
enum class ItemType {
    HELMET,
    ARMOR,
    BOOTS,
    WEAPON_MELEE,
    WEAPON_DISTANT
};

class Item : public IItem {
    ItemType itemType;
public:
    Item(std::string name, std::string description, Characteristics characteristics, ItemType itemType) noexcept;
    ItemType get_item_type() const noexcept;
    Item& operator=(const Item& other) = default;
};
};
