#pragma once
#include <iostream>
#include <string>
#include "model/game_object/character/IPerson.h"
#include "model/inventory/Inventory.h"


namespace superrogue::game_object::character {
class Person : public IPerson {
    std::vector<superrogue::game_object::item::Potion> __used_potions = {};
    void before_any_action();
public:
    superrogue::inventory::Inventory inventory;
    void potion(int potion_i) override;
    void step() override;
    void punch() override;
    Characteristics get_full_characteristics(bool melee);
    Person(std::string name, Characteristics characteristics, IPersonClass person_class, superrogue::inventory::Inventory inventory = superrogue::inventory::Inventory(DEFAULT_POTIONS_MAX)) noexcept;
    Person(const Person& person) = default;
    Person() {};
};
};
