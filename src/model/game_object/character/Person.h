#pragma once
#include <iostream>
#include <string>
#include "model/game_object/character/IPerson.h"
#include "model/inventory/Inventory.h"

using std::string;
using superrogue::inventory::Inventory;


namespace superrogue::game_object::character {
class Person : public IPerson {
    vector<Potion> __used_potions = {};
    void before_any_action();
public:
    Inventory inventory;
    void potion(int potion_i) override;
    void step() override;
    void punch() override;
    Characteristics get_full_characteristics(bool melee);
    Person(string name, Characteristics characteristics, IPersonClass person_class, Inventory inventory = Inventory(DEFAULT_POTIONS_MAX)) noexcept;
    Person() {};
};
};
