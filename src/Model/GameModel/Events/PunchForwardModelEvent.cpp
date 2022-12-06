#include "PunchForwardModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
PunchForwardModelEvent::PunchForwardModelEvent(std::shared_ptr<GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void PunchForwardModelEvent::_execute() {
  map->step(CharacterAction::PUNCH_FORWARD);
}
}; // namespace GameModel::Events
