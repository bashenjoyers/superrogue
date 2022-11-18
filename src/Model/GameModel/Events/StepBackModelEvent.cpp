#include "StepBackModelEvent.h"

using std::shared_ptr;
using std::make_shared;


namespace GameModel::Events {
StepBackModelEvent::StepBackModelEvent(std::shared_ptr<Map::Map> map) : ModelEvent(map) {};

void StepBackModelEvent::_execute() {
    map->step(CharacterAction::STEP_BACK);
}
};
