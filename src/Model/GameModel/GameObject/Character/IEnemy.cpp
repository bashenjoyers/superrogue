#include "IEnemy.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Indifferent.h"

using std::string;

namespace GameModel {
string IEnemy::get_description() const noexcept {
  return enemy_class->get_description();
}

std::shared_ptr<IEnemyClass> IEnemy::get_enemy_class() const noexcept { return enemy_class; }

void IEnemy::disturb() noexcept {
  if (dynamic_cast<Indifferent*>(&*enemy_class) != nullptr) {
    dynamic_cast<Indifferent *>(&*enemy_class)->disturb();
  }
}

float IEnemy::get_attack_range() const noexcept {
  return enemy_class->get_settings().attack_range;
}

IEnemy::IEnemy(string name, Characteristics characteristics,
               std::shared_ptr<IEnemyClass> enemy_class)
    : ICharacter(name, enemy_class->get_description(), characteristics),
      enemy_class(enemy_class){};

bool IEnemy::damaged(int value) noexcept {
  disturb();
  return ICharacter::damaged(value);
}
}; // namespace GameModel
