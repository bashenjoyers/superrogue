#pragma once
#include "model/game_object/item/potions/Potion.h"
#include "model/game_object/item/stuff/Item.h"
#include <optional>
#include <vector>

namespace superrogue::inventory {
class Inventory {
  std::optional<superrogue::game_object::item::Item> helmet = std::nullopt;
  std::optional<superrogue::game_object::item::Item> armor = std::nullopt;
  std::optional<superrogue::game_object::item::Item> boots = std::nullopt;
  std::optional<superrogue::game_object::item::Item> weapon_melee =
      std::nullopt;
  std::optional<superrogue::game_object::item::Item> weapon_distant =
      std::nullopt;
  std::vector<superrogue::game_object::item::Potion> potions = {};
  int __potions_max;

public:
  Inventory(int potions_max = DEFAULT_POTIONS_MAX);
  void set_helmet(std::optional<superrogue::game_object::item::Item> helmet);
  std::optional<superrogue::game_object::item::Item>
  get_helmet() const noexcept;
  void set_armor(std::optional<superrogue::game_object::item::Item> armor);
  std::optional<superrogue::game_object::item::Item> get_armor() const noexcept;
  void set_boots(std::optional<superrogue::game_object::item::Item> boots);
  std::optional<superrogue::game_object::item::Item> get_boots() const noexcept;
  void set_weapon_melee(
      std::optional<superrogue::game_object::item::Item> weapon_melee);
  std::optional<superrogue::game_object::item::Item>
  get_weapon_melee() const noexcept;
  void set_weapon_distant(
      std::optional<superrogue::game_object::item::Item> weapon_distant);
  std::optional<superrogue::game_object::item::Item>
  get_weapon_distant() const noexcept;
  void add_potion(superrogue::game_object::item::Potion potion) noexcept;
  std::vector<superrogue::game_object::item::Potion>
  get_potions() const noexcept;
  superrogue::game_object::item::Potion use_potion(int potion_i);
};
}; // namespace superrogue::inventory
