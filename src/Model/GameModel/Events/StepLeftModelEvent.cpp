#include "StepLeftModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
StepLeftModelEvent::StepLeftModelEvent(std::shared_ptr<Map::World> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void StepLeftModelEvent::_execute() { map->step(CharacterAction::STEP_LEFT); }
}; // namespace GameModel::Events
