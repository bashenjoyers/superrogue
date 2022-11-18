#include "PunchLeftModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
PunchLeftModelEvent::PunchLeftModelEvent(std::shared_ptr<Map::Map> map)
    : ModelEvent(map){};

void PunchLeftModelEvent::_execute() { map->step(CharacterAction::PUNCH_LEFT); }
}; // namespace GameModel::Events
