#include "PunchRightModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace Controller::Events {
PunchRightModelEvent::PunchRightModelEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void PunchRightModelEvent::_execute() {
  map->step(GameModel::CharacterAction::PUNCH_RIGHT);
}
}; // namespace GameModel::Events
