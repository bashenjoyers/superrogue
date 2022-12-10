#include "Lucky.h"

using std::string;

namespace GameModel {

Lucky::Lucky(std::string name)
    : Person(name, "Just lucky Person (has luck >= 0.9)", Inventory::Inventory(DEFAULT_POTIONS_MAX)) {
  characteristics.luck = std::max(characteristics.luck, LUCKY_LUCK);
}
}; // namespace superrogue::GameObject::Character
