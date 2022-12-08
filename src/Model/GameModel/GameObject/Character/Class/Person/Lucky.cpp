#include "Lucky.h"

using std::string;

namespace GameModel {

Lucky::Lucky(std::string name, std::string description, Characteristics characteristics,
             PersonSettings settings,
             Inventory::Inventory inventory)
    : Person(name, description, characteristics, settings, inventory) {

}
}; // namespace superrogue::GameObject::Character
