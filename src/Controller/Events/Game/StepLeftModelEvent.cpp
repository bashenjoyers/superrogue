#include "StepLeftModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace Controller::Events {
StepLeftModelEvent::StepLeftModelEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void StepLeftModelEvent::_execute() { map->step(GameModel::CharacterAction::STEP_LEFT); }
}; // namespace GameModel::Events
