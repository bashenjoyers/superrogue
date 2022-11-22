#include "PunchBackModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
PunchBackModelEvent::PunchBackModelEvent(std::shared_ptr<Map::Map> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void PunchBackModelEvent::_execute() { map->step(CharacterAction::PUNCH_BACK); }
}; // namespace GameModel::Events
