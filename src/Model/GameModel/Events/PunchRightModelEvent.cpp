#include "PunchRightModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
PunchRightModelEvent::PunchRightModelEvent(std::shared_ptr<Map::Map> map)
    : ModelEvent(map){};

void PunchRightModelEvent::_execute() {
  map->step(CharacterAction::PUNCH_RIGHT);
}
}; // namespace GameModel::Events
