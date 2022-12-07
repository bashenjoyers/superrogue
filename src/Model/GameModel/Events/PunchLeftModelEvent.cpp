#include "PunchLeftModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
PunchLeftModelEvent::PunchLeftModelEvent(std::shared_ptr<GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void PunchLeftModelEvent::_execute() { map->step(CharacterAction::PUNCH_LEFT); }
}; // namespace GameModel::Events
