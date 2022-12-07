#include "ICharacter.h"

using std::string;

namespace GameModel {
ICharacter::ICharacter(string name, string description,
                       Characteristics characteristics)
    : IGameObject(name, description, characteristics){}


void ICharacter::takeDamage(int damage) {
  characteristics.health = std::max(characteristics.health - damage, 0);
}

bool ICharacter::isDead() {
  return characteristics.health == 0;
}

};
