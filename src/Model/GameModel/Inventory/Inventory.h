#pragma once
#include "Model/GameModel/GameObject/Item/Potions/Potion.h"
#include "Model/GameModel/GameObject/Item/Stuff/Item.h"
#include <optional>
#include <vector>

/**
 * @brief an entity containing a character's inventory
 * 
 */
namespace GameModel::Inventory {
class Inventory {
  // Item certain type or nothing
  std::optional<Item> helmet = std::nullopt;
  std::optional<Item> armor = std::nullopt;
  std::optional<Item> boots = std::nullopt;
  std::optional<Item> weapon_melee = std::nullopt;
  std::optional<Item> weapon_distant = std::nullopt;
  // potion collection. A limited number that depends on the character class
  std::vector<Potion> potions = {};
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
  void set_helmet(std::optional<Item> helmet);
  std::optional<Item> get_helmet() const noexcept;
  void set_armor(std::optional<Item> armor);
  std::optional<Item> get_armor() const noexcept;
  void set_boots(std::optional<Item> boots);
  std::optional<Item> get_boots() const noexcept;
  void set_weapon_melee(std::optional<Item> weapon_melee);
  std::optional<Item> get_weapon_melee() const noexcept;
  void set_weapon_distant(std::optional<Item> weapon_distant);
  std::optional<Item> get_weapon_distant() const noexcept;
  // adds a potion to the character if there are more than the character can hold the first one is used
  void add_potion(Potion potion) noexcept;
  // returns all potions the character has
  std::vector<Potion> get_potions() const noexcept;
  // uses a potion with a given number
  std::optional<Potion> use_potion(int potion_i);
};
}; // namespace GameModel::Inventory
