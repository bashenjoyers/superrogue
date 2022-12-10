#include "StepRightModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace Controller::Events {
StepRightModelEvent::StepRightModelEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void StepRightModelEvent::_execute() { map->step(GameModel::CharacterAction::STEP_RIGHT); }
}; // namespace GameModel::Events
