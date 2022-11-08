#include "model/inventory/Inventory.h"
#include "model/const.h"
#include "exceptions/exceptions.h"

using superrogue::game_object::item::ItemType;
using superrogue::exception::InventoryException;
using std::optional;
using std::vector;
using superrogue::game_object::item::Item;
using superrogue::game_object::item::Potion;


namespace superrogue::inventory {
Inventory::Inventory(int potions_max) noexcept : __potions_max(potions_max) {}

void Inventory::set_helmet(optional<Item> helmet) {
    if (!helmet.has_value() && helmet.value().get_item_type() != ItemType::HELMET) 
        throw InventoryException("wrong set item helmet");
    __helmet.swap(helmet);
}

optional<Item> Inventory::get_helmet() const noexcept {
    return __helmet;
}

void Inventory::set_armor(optional<Item> armor) {
    if (!armor.has_value() && armor.value().get_item_type() != ItemType::ARMOR) 
        throw InventoryException("wrong set item armor");
    __armor.swap(armor);
}

optional<Item> Inventory::get_armor() const noexcept {
    return __armor;
}

void Inventory::set_boots(optional<Item> boots) {
    if (!boots.has_value() && boots.value().get_item_type() != ItemType::BOOTS) 
        throw InventoryException("wrong set item boots");
    __boots.swap(boots);
}

optional<Item> Inventory::get_boots() const noexcept {
    return __boots;
}

void Inventory::set_weapon_melee(optional<Item> weapon_melee) {
    if (!weapon_melee.has_value() && weapon_melee.value().get_item_type() != ItemType::WEAPON_MELEE) 
        throw InventoryException("wrong set item weapon_melee");
    __weapon_melee.swap(weapon_melee);
}

optional<Item> Inventory::get_weapon_melee() const noexcept {
    return __weapon_melee;
}

void Inventory::set_weapon_distant(optional<Item> weapon_distant) {
    if (!weapon_distant.has_value() && weapon_distant.value().get_item_type() != ItemType::WEAPON_DISTANT) 
        throw InventoryException("wrong set item weapon_distant");
    __weapon_distant.swap(weapon_distant);
}

optional<Item> Inventory::get_weapon_distant() const noexcept {
    return __weapon_distant;
}

void Inventory::add_potion(Potion potion) noexcept {
    if (__potions.size() == __potions_max) {
        use_potion(0);
        __potions.push_back(potion);
    }
}

vector<Potion> Inventory::get_potions() const noexcept {
    return __potions;
}

Potion Inventory::use_potion(int potion_i) {
    if (__potions.size() <= potion_i)
        throw InventoryException("use potion: wrong potion position");
    return *__potions.erase(__potions.begin() + potion_i);
}
};
