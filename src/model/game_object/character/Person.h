#pragma once
#include "model/game_object/character/IPerson.h"
#include "model/inventory/Inventory.h"
#include <iostream>
#include <string>

namespace superrogue::game_object::character {
class Person : public IPerson {
  bool weapon_melee = true;
  std::vector<superrogue::game_object::item::Potion> used_potions = {};
  void before_any_action();

public:
  superrogue::inventory::Inventory inventory;
  void potion(int potion_i) override;
  void step() override;
  void punch() override;
  bool change_weapon() noexcept;
  bool is_weapon_melee() const noexcept;
  void take_item() const noexcept;
  Characteristics get_full_characteristics() const noexcept;
  Person(std::string name, superrogue::Characteristics characteristics,
         superrogue::game_object::character::IPersonClass person_class,
         superrogue::inventory::Inventory inventory =
             superrogue::inventory::Inventory(DEFAULT_POTIONS_MAX));
  Person(const Person &person) = default;
  Person(){};
};
}; // namespace superrogue::game_object::character
