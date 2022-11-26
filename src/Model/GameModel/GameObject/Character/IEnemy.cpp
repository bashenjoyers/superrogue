#include "IEnemy.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Indifferent.h"

using std::string;

namespace GameModel {
std::shared_ptr<IEnemyClass> IEnemy::get_enemy_class() const noexcept {
  return enemy_class;
}

int IEnemy::get_id() const noexcept {
  return id;
}

string IEnemy::get_description() const noexcept {
  return enemy_class->get_description();
}

void IEnemy::disturb() noexcept {
  if (dynamic_cast<Indifferent*>(&*enemy_class) != nullptr) {
    dynamic_cast<Indifferent *>(&*enemy_class)->disturb();
  }
}

float IEnemy::get_attack_range() const noexcept {
  return enemy_class->get_settings().attack_range;
}

IEnemy::IEnemy(string name, Characteristics characteristics,
               std::shared_ptr<IEnemyClass> enemy_class, int id)
    : ICharacter(name, enemy_class->get_description(), characteristics),
      enemy_class(enemy_class), id(id) {};

EnemySettings IEnemy::get_settings() const noexcept {
  return enemy_class->get_settings();
}

CharacterAction IEnemy::strategy(std::vector<Abstract::MapEntityWithPosition> &cells, const Abstract::Position &pos) noexcept {
  return enemy_class->strategy(cells, pos);
}

Abstract::MapEntity IEnemy::get_map_entity() const noexcept {
  return enemy_class->get_map_entity();
}

bool IEnemy::is_vacant(Abstract::MapEntity map_entity) const noexcept {
  return enemy_class->is_vacant(map_entity);
}

bool IEnemy::operator==(const IEnemy &other) const noexcept {
  return this->id == other.id;
}

bool IEnemy::operator<(const IEnemy &other) const noexcept {
  return this->id < other.id;
}

bool IEnemy::damaged(int value) noexcept {
  disturb();
  return ICharacter::damaged(value);
}
}; // namespace GameModel
