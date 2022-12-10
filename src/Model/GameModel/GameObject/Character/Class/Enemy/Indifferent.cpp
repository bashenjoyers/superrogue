#include "Indifferent.h"
#include "Model/GameModel/values.h"

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

Indifferent::Indifferent(std::string name,
                         Characteristics characteristics, EnemySettings settings)
    : Enemy(name,
            "He doesn't care about anyone (ignores everyone if he doesn't start "
            "hitting first)",
            characteristics,
            EnemyStateHolder(std::make_shared<WalkEnemyState>(), EnemyClass::INDIFFERENT, settings, true)) {}

void Indifferent::disturb() noexcept {
  state_holder.disturb();
  Enemy::disturb();
}

MapEntity Indifferent::get_map_entity() const noexcept {
  if (get_settings().intellect < CONCEALMENT_INTELLECT_K)
    return MapEntity::ENEMY_INDIFFERENT;
  return MapEntity::ENEMY;
}
}; // namespace GameModel
