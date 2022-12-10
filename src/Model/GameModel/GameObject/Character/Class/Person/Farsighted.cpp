#include "Farsighted.h"

using std::string;

namespace GameModel {

Farsighted::Farsighted(std::string name) : Person(name,
                                                                           "Can see far away (the field of View is 2 times larger than the "
                                                                           "standard one)",
                                                                Inventory::Inventory(DEFAULT_POTIONS_MAX), PersonSettings {
                                                                  .visible_radius = DEFAULT_VISIBLE_RADIUS * 2
                                                                }) {}
}; // namespace superrogue::GameObject::Character
