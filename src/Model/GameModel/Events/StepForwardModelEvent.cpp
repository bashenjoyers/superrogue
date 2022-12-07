#include "StepForwardModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
StepForwardModelEvent::StepForwardModelEvent(std::shared_ptr<GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void StepForwardModelEvent::_execute() {
  map->step(CharacterAction::STEP_FORWARD);
}
}; // namespace GameModel::Events
