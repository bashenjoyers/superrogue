#include "Flying.h"
#include "Model/GameModel/values.h"

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

Flying::Flying(string description, EnemySettings settings)
    : IEnemyClass(description, EnemyStateHolder(std::make_shared<WalkEnemyState>(), EnemyClass::FLYING, settings)) {}

MapEntity Flying::get_map_entity() const noexcept {
  if (get_settings().intellect < CONCEALMENT_INTELLECT_K)
    return MapEntity::ENEMY_FLYING;
  return MapEntity::ENEMY;
}
}; // namespace GameModel
