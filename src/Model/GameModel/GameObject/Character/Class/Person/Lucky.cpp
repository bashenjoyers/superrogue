#include "Lucky.h"

using std::string;

namespace GameModel {
Lucky::Lucky(string description, PersonSettings settings)
    : IPersonClass(description, settings) {}
}; // namespace superrogue::GameObject::Character
