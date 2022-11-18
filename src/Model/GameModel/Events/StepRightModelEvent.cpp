#include "StepRightModelEvent.h"

using std::shared_ptr;
using std::make_shared;


namespace GameModel::Events {
StepRightModelEvent::StepRightModelEvent(std::shared_ptr<Map::Map> map) : ModelEvent(map) {};

void StepRightModelEvent::_execute() {
    map->step(CharacterAction::STEP_RIGHT);
}
};
