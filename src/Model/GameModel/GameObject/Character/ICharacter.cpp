#include "ICharacter.h"

using std::string;

namespace GameModel {
ICharacter::ICharacter(string name, string description,
                       Characteristics characteristics)
    : IGameObject(name, description, characteristics){}


void ICharacter::take_damage(int damage) {
  characteristics.health = std::max(characteristics.health - damage, 0);
}

bool ICharacter::is_dead() {
  return characteristics.health == 0;
}

};
