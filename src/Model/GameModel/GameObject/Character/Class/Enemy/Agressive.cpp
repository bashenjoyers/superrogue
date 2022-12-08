#include "Agressive.h"
#include "Model/GameModel/values.h"

using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

MapEntity Agressive::get_map_entity() const noexcept {
  if (get_settings().intellect < CONCEALMENT_INTELLECT_K)
    return MapEntity::ENEMY_AGRESSIVE;
  return MapEntity::ENEMY;
}

CharacterAction Agressive::strategy(vector <MapEntityWithPosition> &cells,
                                    const Position &pos) noexcept {
  auto environment = get_environment_info(cells,
                                          pos,
                                          {MapEntity::PERSON, MapEntity::ENEMY, MapEntity::ENEMY_AGRESSIVE,
                                           MapEntity::ENEMY_COWARD, MapEntity::ENEMY_FLYING,
                                           MapEntity::ENEMY_INDIFFERENT, MapEntity::ENEMY_ORDINARY,
                                           MapEntity::ENEMY_TRAVELER});
  return state_holder.step(environment);
}
Agressive::Agressive(std::string name,
                     Characteristics characteristics,
                     int id,
                     EnemySettings settings) :
    Enemy(name,
          "Hates everyone (if he sees at least someone (not necessarily a "
          "Character), he strives to reach him and kill)",
          characteristics,
          id,
          EnemyStateHolder(std::make_shared<WalkEnemyState>(), EnemyClass::AGRESSIVE, settings)) {}
}; // namespace GameModel
