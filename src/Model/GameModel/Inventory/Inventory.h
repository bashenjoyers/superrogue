#pragma once
#include "Model/GameModel/GameObject/Item/Potions/Potion.h"
#include "Model/GameModel/GameObject/Item/Stuff/Item.h"
#include <optional>
#include <vector>
#include <memory>

/**
 * @brief an entity containing a character's inventory
 * 
 */
namespace GameModel::Inventory {

struct InventoryInfo {
  std::vector<Potion> potions = {};
  std::optional<Item> helmet = std::nullopt;
  std::optional<Item> armor = std::nullopt;
  std::optional<Item> boots = std::nullopt;
  std::optional<Item> weapon_melee = std::nullopt;
  std::optional<Item> weapon_distant = std::nullopt;
};


class Inventory {
  // Item certain type or nothing
  std::shared_ptr<Item> helmet = nullptr;
  std::shared_ptr<Item> armor = nullptr;
  std::shared_ptr<Item> boots = nullptr;
  std::shared_ptr<Item> weapon_melee = nullptr;
  std::shared_ptr<Item> weapon_distant = nullptr;
  // potion collection. A limited number that depends on the character class
  std::vector<std::shared_ptr<Potion>> potions = {};
  // maximum number of potions
  int potions_max;

public:
  /**
   * @brief Construct a new Inventory object
   * 
   * @param potions_max - maximum number of potions
   */
  Inventory(int potions_max = DEFAULT_POTIONS_MAX);
  /**
   * @brief creates default inventory
   * 
   * @return Inventory 
   */
  static Inventory getEmptyInventory();

  // getters/setters for Items
  void set_helmet(std::shared_ptr<Item> helmet);
  std::shared_ptr<Item> get_helmet() const noexcept;
  void set_armor(std::shared_ptr<Item> armor);
  std::shared_ptr<Item> get_armor() const noexcept;
  void set_boots(std::shared_ptr<Item> boots);
  std::shared_ptr<Item> get_boots() const noexcept;
  void set_weapon_melee(std::shared_ptr<Item> weapon_melee);
  std::shared_ptr<Item> get_weapon_melee() const noexcept;
  void set_weapon_distant(std::shared_ptr<Item> weapon_distant);
  std::shared_ptr<Item> get_weapon_distant() const noexcept;
  // adds a potion to the character if there are more than the character can hold the first one is used
  void add_potion(std::shared_ptr<Potion> potion) noexcept;
  // returns all potions the character has
  std::vector<std::shared_ptr<Potion>> get_potions() const noexcept;
  // uses a potion with a given number
  std::shared_ptr<Potion> use_potion(int potion_i);

  InventoryInfo get_inventory_info();
};

}; // namespace GameModel::Inventory

