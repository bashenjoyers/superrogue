#include "StepRightModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
StepRightModelEvent::StepRightModelEvent(std::shared_ptr<Map::Map> map)
    : ModelEvent(map){};

void StepRightModelEvent::_execute() { map->step(CharacterAction::STEP_RIGHT); }
}; // namespace GameModel::Events
