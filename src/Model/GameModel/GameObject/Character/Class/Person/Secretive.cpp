#include "Secretive.h"

using std::string;

namespace GameModel {

Secretive::Secretive(std::string name) : Person(name,
                                                                         "Unrealistically secretive one (the field of View of opponents is 2 "
                                                                         "times smaller for the Character)",
                                                              Inventory::Inventory(DEFAULT_POTIONS_MAX)) {

}
}; // namespace superrogue::GameObject::Character
