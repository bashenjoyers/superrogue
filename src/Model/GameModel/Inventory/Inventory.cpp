#include <cassert>
#include "Inventory.h"
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/const.h"

namespace GameModel::Inventory {
Inventory::Inventory(int potions_max) : potions_max(potions_max) {}

Inventory Inventory::getEmptyInventory() { return Inventory(); }

void Inventory::set_helmet(std::shared_ptr<Item> new_helmet) {
  if (new_helmet == nullptr || new_helmet->get_item_type() != ItemType::HELMET)
    throw InventoryException("wrong set Item helmet");
  this->helmet.swap(new_helmet);
}

std::shared_ptr<Item> Inventory::get_helmet() const noexcept { return helmet; }

void Inventory::set_armor(std::shared_ptr<Item> new_armor) {
  if (new_armor == nullptr || new_armor->get_item_type() != ItemType::ARMOR)
    throw InventoryException("wrong set Item armor");
  this->armor.swap(new_armor);
}

std::shared_ptr<Item> Inventory::get_armor() const noexcept { return armor; }

void Inventory::set_boots(std::shared_ptr<Item> new_boots) {
  if (new_boots == nullptr || new_boots->get_item_type() != ItemType::BOOTS)
    throw InventoryException("wrong set Item boots");
  this->boots.swap(new_boots);
}

std::shared_ptr<Item> Inventory::get_boots() const noexcept { return boots; }

void Inventory::set_weapon_melee(std::shared_ptr<Item> new_weapon_melee) {
  if (new_weapon_melee == nullptr ||
	  new_weapon_melee->get_item_type() != ItemType::WEAPON_MELEE)
    throw InventoryException("wrong set Item weapon_melee");
  this->weapon_melee.swap(new_weapon_melee);
}

std::shared_ptr<Item> Inventory::get_weapon_melee() const noexcept {
  return weapon_melee;
}

void Inventory::set_weapon_distant(std::shared_ptr<Item> new_weapon_distant) {
  if (new_weapon_distant == nullptr ||
	  new_weapon_distant->get_item_type() != ItemType::WEAPON_DISTANT)
    throw InventoryException("wrong set Item weapon_distant");
  this->weapon_distant.swap(new_weapon_distant);
}

std::shared_ptr<Item> Inventory::get_weapon_distant() const noexcept {
  return weapon_distant;
}

void Inventory::add_potion(std::shared_ptr<Potion> potion) noexcept {
  if (potions.size() == potions_max) {
    use_potion(0);
  }
  potions.push_back(potion);
}

std::vector<std::shared_ptr<Potion>> Inventory::get_potions() const noexcept { return potions; }

std::shared_ptr<Potion> Inventory::use_potion(int potion_i) {
  if (potions.size() <= potion_i || potion_i < 0)
    return nullptr;
  auto potion = potions[potion_i];
  potions.erase(potions.begin() + potion_i);
  return potion;
}

InventoryInfo Inventory::get_inventory_info() {
  InventoryInfo inf;
  std::vector<Potion> outPotions;

  for (const auto& p: potions) {
	outPotions.emplace_back(*p);
  }

  if (armor != nullptr) inf.armor = *armor;
  if (helmet != nullptr) inf.helmet = *helmet;
  if (boots != nullptr) inf.boots = *boots;
  if (weapon_melee != nullptr) inf.weapon_melee = *weapon_melee;
  if (weapon_distant != nullptr) inf.weapon_distant = *weapon_distant;
  inf.potions = outPotions;

  return inf;
}

}; // namespace GameModel::Inventory
