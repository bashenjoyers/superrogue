#include "Wise.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include <string>

using std::string;

namespace GameModel {

Wise::Wise(std::string name, std::string description, Characteristics characteristics,
           PersonSettings settings,
           Inventory::Inventory inventory)
    : Person(name, description, characteristics, settings, inventory) {

}
}; // namespace superrogue::GameObject::Character
