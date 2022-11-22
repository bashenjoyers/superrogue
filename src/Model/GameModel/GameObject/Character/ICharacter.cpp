#include "ICharacter.h"

using std::string;

namespace GameModel {
ICharacter::ICharacter(string name, string description,
                       Characteristics characteristics)
    : IGameObject(name, description, characteristics){};
};
