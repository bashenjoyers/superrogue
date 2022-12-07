#include "IEnemyClass.h"
#include <algorithm>

using std::find;
using std::string;
using std::vector;

namespace GameModel {
using namespace Abstract;

IEnemyClass::IEnemyClass(string description, EnemyStateHolder state_holder)
    : ICharacterClass(description), state_holder(state_holder) {}

EnemySettings IEnemyClass::get_settings() const noexcept { return state_holder.get_settings(); }

CharacterAction IEnemyClass::strategy(std::vector<MapEntityWithPosition> &cells,
                                      const Position &pos) noexcept {
  auto environment = get_environment_info(cells, pos, {MapEntity::PERSON});
  return state_holder.step(environment);
};

void IEnemyClass::scare() noexcept {
  state_holder.update_state(std::make_shared<CowardEnemyState>());
}
}; // namespace GameModel
