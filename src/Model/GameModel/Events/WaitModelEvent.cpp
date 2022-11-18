#include "WaitModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
WaitModelEvent::WaitModelEvent(std::shared_ptr<Map::Map> map)
    : ModelEvent(map){};

void WaitModelEvent::_execute() { map->step(CharacterAction::WAIT); }
}; // namespace GameModel::Events
