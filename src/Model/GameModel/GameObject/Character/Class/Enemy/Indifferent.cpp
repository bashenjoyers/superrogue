#include "Indifferent.h"
#include "Model/GameModel/values.h"

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

Indifferent::Indifferent(string description, EnemySettings settings)
    : IEnemyClass(description, EnemyStateHolder(std::make_shared<WalkEnemyState>(), EnemyClass::INDIFFERENT, settings, true)) {}

void Indifferent::disturb() noexcept {
  state_holder.disturb();
}

MapEntity Indifferent::get_map_entity() const noexcept {
  if (get_settings().intellect < CONCEALMENT_INTELLECT_K)
    return MapEntity::ENEMY_INDIFFERENT;
  return MapEntity::ENEMY;
}
}; // namespace GameModel
