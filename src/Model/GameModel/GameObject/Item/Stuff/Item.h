#pragma once
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/GameObject/Item/IItem.h"
#include "Model/GameModel/const.h"

namespace GameModel {
/**
 * @brief type of item (determines where it can be worn)
 * the character can choose melee or ranged weapons if he has them (by default, there are melee weapons - conditionally, you can just hit with your hands). Ranged weapons have increased attack range
 * 
 */
enum class ItemType { HELMET, ARMOR, BOOTS, WEAPON_MELEE, WEAPON_DISTANT };

class Item : public IItem {
  ItemType itemType;

public:
  /**
   * @brief Construct a new Item with all the properties inherent in each object and object type
   * 
   */
  Item(std::string name, std::string description,
       Characteristics characteristics, ItemType itemType);

  Item(const Item &other) = default;
  Item() = default;

  // returns the type of the item
  ItemType get_item_type() const noexcept;
  // operator to set a item
  Item &operator=(const Item &other) = default;

    Abstract::MapEntity getMapEntity() override;
};
}; // namespace GameModel
