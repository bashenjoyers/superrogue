#include "model/game_object/character/Person.h"
#include "model/const.h"


namespace superrogue::game_object::character {
void Person::before_any_action() {      // TODO(do it adequately)
    vector<int> delete_potions_i = {};
    int i = 0;
    for (Potion potion : __used_potions) {
        potion.step();
        if (!potion.is_work()) {
            delete_potions_i.push_back(i);
        }
        i++;
    }
    if (delete_potions_i.size() != 0) {
        std::reverse(delete_potions_i.begin(), delete_potions_i.end());
        vector<Potion> new_used_potions = {};
        for (int i = 0; i < __used_potions.size(); i++) {
            if (delete_potions_i.size() != 0 && i == delete_potions_i.back()) {
                delete_potions_i.pop_back();
                continue;
            }
            new_used_potions.push_back(__used_potions[i]);
        }
        __used_potions = new_used_potions;
    }
}

void Person::potion(int potion_i) {
    before_any_action();
    Potion potion = inventory.use_potion(potion_i);
}

void Person::step() {
    before_any_action();
}

void Person::punch() {
    before_any_action();
}

Characteristics Person::get_full_characteristics(bool melee = true) {    // TODO(do it adequately)
    Characteristics full_characteristics = this->characteristics;
    vector<optional<Item>> items = {
        inventory.get_helmet(),
        inventory.get_armor(),
        inventory.get_boots(),
        melee ? inventory.get_weapon_melee() : inventory.get_weapon_distant()
    };
    for (optional<Item> item : items) {
        if (item.has_value())
            full_characteristics += item.value().characteristics;
    }
    for (Potion potion : __used_potions) {
        full_characteristics += potion.characteristics;
    }
    return full_characteristics;   
}

Person::Person(string name, Characteristics characteristics, IPersonClass person_class, Inventory inventory) noexcept :
    IPerson(name, characteristics, person_class), inventory(inventory) {};
};
