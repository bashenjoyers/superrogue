#include "Person.h"
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/const.h"

using std::optional;
using std::string;
using std::vector;

namespace GameModel {
void Person::before_any_action() { // FIXME(do it adequately)
  vector<int> delete_potions_i = {};
  int i = 0;
  for (Potion potion : used_potions) {
    potion.step();
    if (!potion.is_work()) {
      delete_potions_i.push_back(i);
    }
    i++;
  }
  if (delete_potions_i.size() != 0) {
    std::reverse(delete_potions_i.begin(), delete_potions_i.end());
    vector<Potion> new_used_potions = {};
    for (int i = 0; i < used_potions.size(); i++) {
      if (delete_potions_i.size() != 0 && i == delete_potions_i.back()) {
        delete_potions_i.pop_back();
        continue;
      }
      new_used_potions.push_back(used_potions[i]);
    }
    used_potions = new_used_potions;
  }
}

void Person::potion(int potion_i) {
  before_any_action();
  Potion potion = inventory.use_potion(potion_i);
  int health = potion.get_characteristics().health;
  if (health != 0) { // health potion
    this->add_health(health);
  } else {
    used_potions.push_back(potion);
  }
}

void Person::step() { before_any_action(); }

void Person::punch() { before_any_action(); }

bool Person::change_weapon() noexcept {
  if (weapon_melee && !inventory.get_weapon_distant().has_value())
    return false;
  weapon_melee = !weapon_melee;
  return true;
}

bool Person::is_weapon_melee() const noexcept { return weapon_melee; }

void Person::take_item() const noexcept {}

Characteristics
Person::get_full_characteristics() const noexcept { // FIXME(do it adequately)
  Characteristics full_characteristics =
      get_characteristics() + level_characteristics;
  vector<optional<Item>> items = {
      inventory.get_helmet(), inventory.get_armor(), inventory.get_boots(),
      weapon_melee ? inventory.get_weapon_melee()
                   : inventory.get_weapon_distant()};
  for (optional<Item> item : items) {
    if (item.has_value())
      full_characteristics += item.value().get_characteristics();
  }
  for (Potion potion : used_potions) {
    full_characteristics += potion.get_characteristics();
  }
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

Person::Person(string name, Characteristics characteristics,
               IPersonClass person_class, Inventory::Inventory inventory)
    : IPerson(name, characteristics, person_class), inventory(inventory){};
}; // namespace superrogue::GameObject::Character
