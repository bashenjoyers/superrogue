#include "Coward.h"
#include "Model/GameModel/values.h"
#include <vector>

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

Coward::Coward(string description, EnemySettings settings)
    : IEnemyClass(description, EnemyStateHolder(std::make_shared<CowardEnemyState>(), EnemyClass::COWARD, settings)) {}

MapEntity Coward::get_map_entity() const noexcept {
  if (get_settings().intellect < CONCEALMENT_INTELLECT_K)
    return MapEntity::ENEMY_COWARD;
  return MapEntity::ENEMY;
}
}; // namespace GameModel
