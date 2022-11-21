#pragma once
#include "IPerson.h"
#include "Model/GameModel/GameObject/Character/Class/Person/IPersonClass.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/GameObject/Item/Potions/Potion.h"
#include "Model/GameModel/Inventory/Inventory.h"
#include <iostream>
#include <string>

namespace GameModel {
// Person class contains all parameters about him and actions
class Person : public IPerson {
  // melee weapon selected
  bool weapon_melee = true;
  // individual characteristics obtained with the level
  Characteristics level_characteristics = Characteristics();
  // collection of used potions
  std::vector<Potion> used_potions = {};
  // function called before all actions
  void before_any_action();

public:
  // inventory with things and potions
  Inventory::Inventory inventory;
  /**
   * @brief uses the potion by its number in the collection
   * 
   * @param potion_i - number
   */
  void potion(int potion_i) override;
  // called when the character steps
  void step() override;
  // called when the character punch smb
  void punch() override;
  // changes the type of the current weapon if possible. Returns the success of the operation
  bool change_weapon() noexcept;
  // returns whether the selected weapon is a melee weapon
  bool is_weapon_melee() const noexcept;
  // called when the item is changed
  void take_item() const noexcept;
  /**
   * @brief Get the full characteristics object. Sums up character stats, stats gained from level, item stats, and temporary stats from potions
   * 
   * @return Characteristics 
   */
  Characteristics get_full_characteristics() const noexcept;
  // called when passing a level. Adds passed stats to the character. Increases his health by a certain amount
  void level_up(Characteristics characteristics);
  /**
   * @brief Construct a new Person according to the standard characteristics of the object and inventory
   */
  Person(std::string name, Characteristics characteristics,
         std::shared_ptr<IPersonClass> person_class,
         Inventory::Inventory inventory =
             Inventory::Inventory(DEFAULT_POTIONS_MAX));
  Person(const Person &person) = default;
  Person(){};
};
}; // namespace GameModel
