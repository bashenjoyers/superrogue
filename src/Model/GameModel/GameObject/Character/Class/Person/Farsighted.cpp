#include "Farsighted.h"

using std::string;

namespace GameModel {

Farsighted::Farsighted(std::string name) : Person(name,
                                                                           "Can see far away (the field of View is 2 times larger than the "
                                                                           "standard one)",
                                                                Inventory::Inventory(DEFAULT_POTIONS_MAX)) {
  settings.visible_radius = settings.visible_radius * 2;
}
}; // namespace superrogue::GameObject::Character
