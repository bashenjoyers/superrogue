#include "Flying.h"
#include "Model/GameModel/values.h"

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

MapEntity Flying::get_map_entity() const noexcept {
  if (get_settings().intellect < CONCEALMENT_INTELLECT_K)
    return MapEntity::ENEMY_FLYING;
  return MapEntity::ENEMY;
}
Flying::Flying(std::string name,
               Characteristics characteristics,
               int id,
               EnemySettings settings) :
    Enemy(name,
          "Looks down on everyone (can ignore all obstacles (walls))",
          characteristics,
          id,
          EnemyStateHolder(std::make_shared<WalkEnemyState>(), EnemyClass::FLYING, settings)) {}
}; // namespace GameModel
