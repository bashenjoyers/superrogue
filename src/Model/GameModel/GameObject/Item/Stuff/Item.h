#pragma once
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/const.h"
#include "Model/GameModel/GameObject/Item/IItem.h"

namespace GameModel {
enum class ItemType { HELMET, ARMOR, BOOTS, WEAPON_MELEE, WEAPON_DISTANT };

class Item : public IItem {
  ItemType itemType;

public:
  Item(std::string name, std::string description,
       Characteristics characteristics, ItemType itemType);
  ItemType get_item_type() const noexcept;
  Item &operator=(const Item &other) = default;
};
}; // namespace superrogue::GameObject::Item
