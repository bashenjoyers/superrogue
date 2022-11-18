#pragma once
#include "IPerson.h"
#include "Model/GameModel/GameObject/Character/Class/Person/IPersonClass.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/GameObject/Item/Potions/Potion.h"
#include "Model/GameModel/Inventory/Inventory.h"
#include <iostream>
#include <string>

namespace GameModel {
class Person : public IPerson {
  bool weapon_melee = true;
  Characteristics level_characteristics = Characteristics();
  std::vector<Potion> used_potions = {};
  void before_any_action();

public:
  Inventory::Inventory inventory;
  void potion(int potion_i) override;
  void step() override;
  void punch() override;
  bool change_weapon() noexcept;
  bool is_weapon_melee() const noexcept;
  void take_item() const noexcept;
  Characteristics get_full_characteristics() const noexcept;
  void level_up(Characteristics characteristics);
  Person(std::string name, Characteristics characteristics,
         IPersonClass person_class,
         Inventory::Inventory inventory =
             Inventory::Inventory(DEFAULT_POTIONS_MAX));
  Person(const Person &person) = default;
  Person(){};
};
}; // namespace GameModel
