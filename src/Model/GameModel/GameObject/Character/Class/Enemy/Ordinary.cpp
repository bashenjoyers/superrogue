#include "Ordinary.h"
#include "Model/GameModel/values.h"
#include <vector>

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

Ordinary::Ordinary(std::string name,
                   std::string description,
                   Characteristics characteristics,
                   int id,
                   EnemySettings settings) :
    Enemy(name,
          description,
          characteristics,
          id,
          EnemyStateHolder(std::make_shared<WalkEnemyState>(), EnemyClass::ORDINARY, settings)) {}

MapEntity Ordinary::get_map_entity() const noexcept {
  if (get_settings().intellect < CONCEALMENT_INTELLECT_K)
    return MapEntity::ENEMY_ORDINARY;
  return MapEntity::ENEMY;
}
}; // namespace GameModel
