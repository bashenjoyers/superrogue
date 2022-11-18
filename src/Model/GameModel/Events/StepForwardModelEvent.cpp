#include "StepForwardModelEvent.h"

using std::shared_ptr;
using std::make_shared;


namespace GameModel::Events {
StepForwardModelEvent::StepForwardModelEvent(std::shared_ptr<Map::Map> map) : ModelEvent(map) {};

void StepForwardModelEvent::_execute() {
    map->step(CharacterAction::STEP_FORWARD);
}
};
