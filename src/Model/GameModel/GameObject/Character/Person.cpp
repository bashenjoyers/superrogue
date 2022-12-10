#include <cassert>
#include "Person.h"
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/const.h"
#include "Model/GameModel/generation_utils.h"

using std::optional;
using std::string;
using std::vector;

namespace GameModel {
void Person::before_any_action() {
  vector<std::shared_ptr<Potion>> new_used_potions = {};
  for (std::shared_ptr<Potion> potion : used_potions) {
	potion->step();
	if (potion->is_work()) {
	  new_used_potions.push_back(potion);
	}
  }
  this->used_potions = new_used_potions;
}

void Person::potion(int potion_i) {
  before_any_action();
  std::shared_ptr<Potion> potion = inventory.use_potion(potion_i);
  if (potion != nullptr) {
	int health = potion->get_characteristics().health;
	if (health != 0) { // health potion
	  this->add_health(health);
	} else {
	  used_potions.push_back(potion);
	}
  }
}

void Person::step() { before_any_action(); }

void Person::punch() { before_any_action(); }

bool Person::change_weapon() noexcept {
  before_any_action();
  if (weapon_melee && inventory.get_weapon_distant() == nullptr)
	return false;
  weapon_melee = !weapon_melee;
  return true;
}

bool Person::is_weapon_melee() const noexcept { return weapon_melee; }

Characteristics
Person::get_full_characteristics() const noexcept {
  Characteristics full_characteristics =
	  get_characteristics() + level_characteristics;
  vector<std::shared_ptr<Item>> items = {
	  inventory.get_helmet(), inventory.get_armor(), inventory.get_boots(),
	  weapon_melee ? inventory.get_weapon_melee()
				   : inventory.get_weapon_distant()};
  for (std::shared_ptr<Item> item : items) {
	if (item != nullptr)
	  full_characteristics += item->get_characteristics();
  }
  for (std::shared_ptr<Potion> potion : used_potions) {
	full_characteristics += potion->get_characteristics();
  }
  full_characteristics.armor = std::max(full_characteristics.armor, 0);
  full_characteristics.damage = std::max(full_characteristics.damage, 0);
  full_characteristics.dexterity = std::max(full_characteristics.dexterity, 0);
  return full_characteristics;
}

void Person::level_up(Characteristics characteristics) {
  if (characteristics.luck != 0 || characteristics.health != 0 ||
	  (characteristics.armor + characteristics.damage +
		  characteristics.dexterity !=
		  POINTS_LVL_UP)) {
	throw GameObjectException("too many points in lvl_up");
  }
  level_characteristics += characteristics;
  level_characteristics.health += HEALTH_LVL_K;
}

Person::Person(std::string name,
               std::string description,
               Inventory::Inventory inventory)
	: ICharacter(name, description, Characteristics()), inventory(inventory) {
  int points = int(POINTS_IN_LVL);
  int health_default = int(HEALTH_LVL_K);
  int damage =
      int(GameModel::Generation::characteristic_gen(Values::generator) /
          PARAMETER_COUNT * points) + 1;
  int armor = int(GameModel::Generation::characteristic_gen(Values::generator) /
      PARAMETER_COUNT * points) + 1;
  int health =
      int(GameModel::Generation::characteristic_gen(Values::generator) /
          PARAMETER_COUNT * points);
  int dexterity =
      int(GameModel::Generation::characteristic_gen(Values::generator) /
          PARAMETER_COUNT * points);
  float luck = GameModel::Generation::luck_gen(Values::generator);
  characteristics = Characteristics(damage, armor, health_default + health, dexterity,
                                    luck);
}

int Person::get_attack_range() const noexcept {
  return weapon_melee ? 1 : DISTANT_RANGE;
}

std::shared_ptr<IItem> Person::take_item(std::shared_ptr<IItem> item) noexcept {
  if (auto potion = std::dynamic_pointer_cast<Potion>(item); potion != nullptr) {
	take_potion(potion);
	return nullptr;
  } else if (auto equipment = std::dynamic_pointer_cast<Item>(item); equipment != nullptr) {
	return take_equipment(equipment);
  } else {
	assert(false);
  }
}

std::shared_ptr<Item> Person::take_equipment(std::shared_ptr<Item> new_equipment) {
  switch (new_equipment->get_item_type()) {
  case ItemType::HELMET: {
	std::shared_ptr<Item> previous_item = inventory.get_helmet();
	inventory.set_helmet(new_equipment);
	return previous_item;
  }
  case ItemType::ARMOR: {
	std::shared_ptr<Item> previous_item = inventory.get_armor();
	inventory.set_armor(new_equipment);
	return previous_item;
  }
  case ItemType::BOOTS: {
	std::shared_ptr<Item> previous_item = inventory.get_boots();
	inventory.set_boots(new_equipment);
	return previous_item;
  }
  case ItemType::WEAPON_MELEE: {
	std::shared_ptr<Item> previous_item = inventory.get_weapon_melee();
	inventory.set_weapon_melee(new_equipment);
	return previous_item;
  }
  case ItemType::WEAPON_DISTANT: {
	std::shared_ptr<Item> previous_item = inventory.get_weapon_distant();
	inventory.set_weapon_distant(new_equipment);
	return previous_item;
  }

  default: throw GameObjectException("wrong Item type");
  }
}

void Person::take_potion(std::shared_ptr<Potion> new_potion) {
	inventory.add_potion(new_potion);
}
Inventory::InventoryInfo Person::get_inventory_info() {
  return inventory.get_inventory_info();
}

Abstract::MapEntity Person::get_map_entity() const noexcept {
  return Abstract::MapEntity::PERSON;
}
PersonSettings Person::get_settings() {
  return settings;
}

}; // namespace GameModel
