#include "StepBackModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace Controller::Events {
StepBackModelEvent::StepBackModelEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void StepBackModelEvent::_execute() { map->step(GameModel::CharacterAction::STEP_BACK); }
}; // namespace GameModel::Events
