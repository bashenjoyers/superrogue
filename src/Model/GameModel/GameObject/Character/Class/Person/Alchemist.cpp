#include "Alchemist.h"

using std::string;

namespace GameModel {
Alchemist::Alchemist(string description, PersonSettings settings)
    : IPersonClass(description, settings) {}
}; // namespace superrogue::GameObject::Character
