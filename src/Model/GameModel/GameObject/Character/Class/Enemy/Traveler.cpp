#include "Traveler.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/values.h"

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

MapEntity Traveler::get_map_entity() const noexcept {
  if (get_settings().intellect < CONCEALMENT_INTELLECT_K)
    return MapEntity::ENEMY_TRAVELER;
  return MapEntity::ENEMY;
}

Traveler::Traveler(std::string name,
                   Characteristics characteristics,
                   EnemySettings settings) :
    Enemy(name,
          "Can be anywhere he wants (he can be located anywhere on the Map)",
          characteristics,
          EnemyStateHolder(std::make_shared<WalkEnemyState>(), EnemyClass::TRAVELER, settings)) {}

}; // namespace GameModel
