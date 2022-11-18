#include "PunchForwardModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
PunchForwardModelEvent::PunchForwardModelEvent(std::shared_ptr<Map::Map> map)
    : ModelEvent(map){};

void PunchForwardModelEvent::_execute() {
  map->step(CharacterAction::PUNCH_FORWARD);
}
}; // namespace GameModel::Events
