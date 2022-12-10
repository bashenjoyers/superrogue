#include "Wise.h"
#include "Model/GameModel/GameObject/Characteristics.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include <string>

using std::string;

namespace GameModel {

Wise::Wise(std::string name)
    : Person(name, "The wisest elder (can see the areas where opponents may be located)", Inventory::Inventory(DEFAULT_POTIONS_MAX), PersonSettings {
        .visible_enemy = true
    }) {}
}; // namespace superrogue::GameObject::Character
