#include "PunchForwardModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace Controller::Events {
PunchForwardModelEvent::PunchForwardModelEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void PunchForwardModelEvent::_execute() {
  map->step(GameModel::CharacterAction::PUNCH_FORWARD);
}
}; // namespace GameModel::Events
