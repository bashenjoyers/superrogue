#include "Coward.h"
#include "Model/GameModel/values.h"
#include <vector>

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

MapEntity Coward::get_map_entity() const noexcept {
  if (get_settings().intellect < CONCEALMENT_INTELLECT_K)
    return MapEntity::ENEMY_COWARD;
  return MapEntity::ENEMY;
}

Coward::Coward(std::string name,
               std::string description,
               Characteristics characteristics,
               int id,
               EnemySettings settings) :
    Enemy(name,
          description,
          characteristics,
          id,
          EnemyStateHolder(std::make_shared<CowardEnemyState>(), EnemyClass::COWARD, settings)) {}

}; // namespace GameModel
