#include "StepForwardModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
StepForwardModelEvent::StepForwardModelEvent(std::shared_ptr<Map::Map> map)
    : ModelEvent(map){};

void StepForwardModelEvent::_execute() {
  map->step(CharacterAction::STEP_FORWARD);
}
}; // namespace GameModel::Events
