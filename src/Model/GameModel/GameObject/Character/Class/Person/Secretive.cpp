#include "Secretive.h"

using std::string;

namespace GameModel {

Secretive::Secretive(std::string name, std::string description, Characteristics characteristics,
                     PersonSettings settings,
                     Inventory::Inventory inventory) : Person(name,
                                                              description,
                                                              characteristics,
                                                              settings,
                                                              inventory) {

}
}; // namespace superrogue::GameObject::Character
