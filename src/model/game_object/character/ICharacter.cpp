#include "model/game_object/character/ICharacter.h"

using std::string;

namespace superrogue::game_object::character {
ICharacter::ICharacter(string name, string description,
                       Characteristics characteristics)
    : IGameObject(name, description, characteristics){};
};
