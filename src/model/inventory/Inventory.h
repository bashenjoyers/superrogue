#pragma once
#include <optional>
#include <vector>
#include "model/game_object/item/stuff/Item.h"
#include "model/game_object/item/potions/Potion.h"

using std::optional;
using std::nullopt;
using std::vector;
using superrogue::game_object::item::Item;
using superrogue::game_object::item::Potion;


namespace superrogue::inventory {
class Inventory {
    optional<Item> __helmet = nullopt;
    optional<Item> __armor = nullopt;
    optional<Item> __boots = nullopt;
    optional<Item> __weapon_melee = nullopt;
    optional<Item> __weapon_distant = nullopt;
    vector<Potion> __potions = {};
    int __potions_max;
public:
    Inventory(int potions_max = DEFAULT_POTIONS_MAX) noexcept;
    void set_helmet(optional<Item> helmet);
    optional<Item> get_helmet() const noexcept;
    void set_armor(optional<Item> armor);
    optional<Item> get_armor() const noexcept;
    void set_boots(optional<Item> boots);
    optional<Item> get_boots() const noexcept;
    void set_weapon_melee(optional<Item> weapon_melee);
    optional<Item> get_weapon_melee() const noexcept;
    void set_weapon_distant(optional<Item> weapon_distant);
    optional<Item> get_weapon_distant() const noexcept;
    void add_potion(Potion potion) noexcept;
    vector<Potion> get_potions() const noexcept;
    Potion use_potion(int potion_i);
};
};
