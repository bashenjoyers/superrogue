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
                   std::string description,
                   Characteristics characteristics,
                   int id,
                   EnemySettings settings) :
    Enemy(name,
          description,
          characteristics,
          id,
          EnemyStateHolder(std::make_shared<WalkEnemyState>(), EnemyClass::TRAVELER, settings)) {}

}; // namespace GameModel
