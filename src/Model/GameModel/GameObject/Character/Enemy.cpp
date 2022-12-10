#include "Enemy.h"
#include "Model/GameModel/GameObject/Character/Class/Enemy/Indifferent.h"
#include "Model/GameModel/abstract.h"

using std::string;

namespace GameModel {

void Enemy::disturb() noexcept {
  if (get_characteristics().health < init_health * ENEMY_SCARED_K) {
    scare();
  }
}

int Enemy::get_attack_range() const noexcept {
  return state_holder.get_settings().attack_range;
}

Enemy::Enemy(std::string name, std::string description, Characteristics characteristics, EnemyStateHolder state_holder)
    : ICharacter(name, description, characteristics),
       init_health(characteristics.health), state_holder(state_holder) {};

EnemySettings Enemy::get_settings() const noexcept {
  return state_holder.get_settings();
}

CharacterAction Enemy::strategy(std::vector<Abstract::MapEntityWithPosition> &cells, const Abstract::Position &pos) noexcept {
  auto environment = get_environment_info(cells, pos, {Abstract::MapEntity::PERSON});
  return state_holder.step(environment);
}

bool Enemy::is_vacant(Abstract::MapEntity map_entity) const noexcept {
  return GameModel::is_vacant(map_entity);
}

void Enemy::take_damage(int damage) {
  ICharacter::take_damage(damage);
  disturb();
}

void Enemy::scare() noexcept {
  state_holder.update_state(std::make_shared<CowardEnemyState>());
}
std::shared_ptr<Enemy> Enemy::replicate() {
  return nullptr;
}

}; // namespace GameModel
