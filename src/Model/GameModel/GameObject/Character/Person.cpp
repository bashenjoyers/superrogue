#include "Person.h"
#include "Model/Exceptions/exceptions.h"
#include "Model/GameModel/const.h"

using std::optional;
using std::string;
using std::vector;

namespace GameModel {
void Person::before_any_action() {
  vector<Potion> new_used_potions = {};
  for (Potion potion : used_potions) {
    potion.step();
    if (potion.is_work()) {
      new_used_potions.push_back(potion);
    }
  }
  this->used_potions = new_used_potions;
}

void Person::potion(int potion_i) {
  before_any_action();
  optional<Potion> potion_opt = inventory.use_potion(potion_i);
  if (potion_opt != std::nullopt) {
    Potion potion = potion_opt.value();
    int health = potion.get_characteristics().health;
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

Person::Person(string name, Characteristics characteristics,
               std::shared_ptr<IPersonClass> person_class, Inventory::Inventory inventory)
    : IPerson(name, characteristics, person_class), inventory(inventory){} 
}; // namespace GameModel
