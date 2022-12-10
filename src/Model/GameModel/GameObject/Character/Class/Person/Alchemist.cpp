#include "Alchemist.h"

using std::string;

namespace GameModel {

Alchemist::Alchemist(std::string name) : Person(name,
                                                                         "A novice alchemist (can have up to 7 Potions)",
                                                                         Inventory::Inventory(POTIONS_MAX_ALCHEMIST)) {

}
}; // namespace superrogue::GameObject::Character
