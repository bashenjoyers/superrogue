#include "StepBackModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
StepBackModelEvent::StepBackModelEvent(std::shared_ptr<GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void StepBackModelEvent::_execute() { map->step(CharacterAction::STEP_BACK); }
}; // namespace GameModel::Events
