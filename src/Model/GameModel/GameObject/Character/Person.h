#pragma once
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/GameObject/Item/Potions/Potion.h"
#include "Model/GameModel/Inventory/Inventory.h"
#include "ICharacter.h"
#include <iostream>
#include <string>

namespace GameModel {

/**
 * @brief Person settings
 *
 */
struct PersonSettings {
  // character visibility range
  int visible_radius = DEFAULT_VISIBLE_RADIUS;
};

// Person class contains all parameters about him and actions
class Person : public ICharacter {
  // melee weapon selected
  bool weapon_melee = true;
  // individual characteristics obtained with the level
  Characteristics level_characteristics = Characteristics();
  // collection of used potions
  std::vector<std::shared_ptr<Potion>> used_potions = {};
  // function called before all actions
  void before_any_action();

  Inventory::Inventory inventory;

  void take_potion(std::shared_ptr<Potion> new_potion);
  std::shared_ptr<Item> take_equipment(std::shared_ptr<Item> new_equipment);
protected:
  PersonSettings settings;
public:
  /**
   * @brief uses the potion by its number in the collection
   * 
   * @param potion_i - number
   */
  void potion(int potion_i);
  // called when the character steps
  void step() override;
  // called when the character punch smb
  void punch() override;
  // changes the type of the current weapon if possible. Returns the success of the operation
  bool change_weapon() noexcept;
  // returns whether the selected weapon is a melee weapon
  bool is_weapon_melee() const noexcept;
  // called when the item is changed
  std::shared_ptr<IItem> take_item(std::shared_ptr<IItem> item) noexcept;

  Inventory::InventoryInfo get_inventory_info();

  PersonSettings get_settings();

  virtual int get_attack_range() const noexcept override;

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
  Person(std::string name,
         std::string description,
         Inventory::Inventory inventory = Inventory::Inventory(DEFAULT_POTIONS_MAX));
  Person(const Person &person) = default;
  Person() {};
  virtual ~Person() = default;
  Abstract::MapEntity get_map_entity() const noexcept override;
};
}; // namespace GameModel
