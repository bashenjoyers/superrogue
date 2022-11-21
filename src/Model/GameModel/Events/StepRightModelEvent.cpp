#include "StepRightModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
StepRightModelEvent::StepRightModelEvent(std::shared_ptr<Map::Map> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void StepRightModelEvent::_execute() { map->step(CharacterAction::STEP_RIGHT); }
}; // namespace GameModel::Events
