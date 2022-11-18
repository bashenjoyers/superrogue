#include "StepLeftModelEvent.h"

using std::shared_ptr;
using std::make_shared;


namespace GameModel::Events {
StepLeftModelEvent::StepLeftModelEvent(std::shared_ptr<Map::Map> map) : ModelEvent(map) {};

void StepLeftModelEvent::_execute() {
    map->step(CharacterAction::STEP_LEFT);
}
};
