#pragma once
#include "Model/GameModel/GameObject/Item/Potions/Potion.h"
#include "Model/GameModel/GameObject/Item/Stuff/Item.h"
#include <optional>
#include <vector>

namespace GameModel::Inventory {
class Inventory {
  std::optional<Item> helmet = std::nullopt;
  std::optional<Item> armor = std::nullopt;
  std::optional<Item> boots = std::nullopt;
  std::optional<Item> weapon_melee =
      std::nullopt;
  std::optional<Item> weapon_distant =
      std::nullopt;
  std::vector<Potion> potions = {};
  int potions_max;

public:
  Inventory(int potions_max = DEFAULT_POTIONS_MAX);
  static Inventory getEmptyInventory();

  void set_helmet(std::optional<Item> helmet);
  std::optional<Item>
  get_helmet() const noexcept;
  void set_armor(std::optional<Item> armor);
  std::optional<Item> get_armor() const noexcept;
  void set_boots(std::optional<Item> boots);
  std::optional<Item> get_boots() const noexcept;
  void set_weapon_melee(
      std::optional<Item> weapon_melee);
  std::optional<Item>
  get_weapon_melee() const noexcept;
  void set_weapon_distant(
      std::optional<Item> weapon_distant);
  std::optional<Item>
  get_weapon_distant() const noexcept;
  void add_potion(Potion potion) noexcept;
  std::vector<Potion>
  get_potions() const noexcept;
  Potion use_potion(int potion_i);
};
}; // namespace superrogue::Inventory
