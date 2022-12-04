#include "WaitModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
WaitModelEvent::WaitModelEvent(std::shared_ptr<Map::World> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void WaitModelEvent::_execute() { map->step(CharacterAction::WAIT); }
}; // namespace GameModel::Events
