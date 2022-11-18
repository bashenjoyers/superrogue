#include "StepBackModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
StepBackModelEvent::StepBackModelEvent(std::shared_ptr<Map::Map> map)
    : ModelEvent(map){};

void StepBackModelEvent::_execute() { map->step(CharacterAction::STEP_BACK); }
}; // namespace GameModel::Events
