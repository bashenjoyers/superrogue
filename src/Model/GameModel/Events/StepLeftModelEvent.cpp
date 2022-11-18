#include "StepLeftModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
StepLeftModelEvent::StepLeftModelEvent(std::shared_ptr<Map::Map> map)
    : ModelEvent(map){};

void StepLeftModelEvent::_execute() { map->step(CharacterAction::STEP_LEFT); }
}; // namespace GameModel::Events
