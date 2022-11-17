#include "model/inventory/Inventory.h"
#include "exceptions/exceptions.h"
#include "model/const.h"

using std::optional;
using std::vector;
using superrogue::exception::InventoryException;
using superrogue::game_object::item::Item;
using superrogue::game_object::item::ItemType;
using superrogue::game_object::item::Potion;

namespace superrogue::inventory {
Inventory::Inventory(int potions_max) : __potions_max(potions_max) {}

void Inventory::set_helmet(optional<Item> helmet) {
  if (!helmet.has_value() && helmet.value().get_item_type() != ItemType::HELMET)
    throw InventoryException("wrong set item helmet");
  helmet.swap(helmet);
}

optional<Item> Inventory::get_helmet() const noexcept { return helmet; }

void Inventory::set_armor(optional<Item> armor) {
  if (!armor.has_value() && armor.value().get_item_type() != ItemType::ARMOR)
    throw InventoryException("wrong set item armor");
  armor.swap(armor);
}

optional<Item> Inventory::get_armor() const noexcept { return armor; }

void Inventory::set_boots(optional<Item> boots) {
  if (!boots.has_value() && boots.value().get_item_type() != ItemType::BOOTS)
    throw InventoryException("wrong set item boots");
  boots.swap(boots);
}

optional<Item> Inventory::get_boots() const noexcept { return boots; }

void Inventory::set_weapon_melee(optional<Item> weapon_melee) {
  if (!weapon_melee.has_value() &&
      weapon_melee.value().get_item_type() != ItemType::WEAPON_MELEE)
    throw InventoryException("wrong set item weapon_melee");
  weapon_melee.swap(weapon_melee);
}

optional<Item> Inventory::get_weapon_melee() const noexcept {
  return weapon_melee;
}

void Inventory::set_weapon_distant(optional<Item> weapon_distant) {
  if (!weapon_distant.has_value() &&
      weapon_distant.value().get_item_type() != ItemType::WEAPON_DISTANT)
    throw InventoryException("wrong set item weapon_distant");
  weapon_distant.swap(weapon_distant);
}

optional<Item> Inventory::get_weapon_distant() const noexcept {
  return weapon_distant;
}

void Inventory::add_potion(Potion potion) noexcept {
  if (potions.size() == __potions_max) {
    use_potion(0);
    potions.push_back(potion);
  }
}

vector<Potion> Inventory::get_potions() const noexcept { return potions; }

Potion Inventory::use_potion(int potion_i) {
  if (potions.size() <= potion_i)
    throw InventoryException("use potion: wrong potion position");
  return *potions.erase(potions.begin() + potion_i);
}
}; // namespace superrogue::inventory
