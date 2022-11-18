#include "PunchForwardModelEvent.h"

using std::shared_ptr;
using std::make_shared;


namespace GameModel::Events {
PunchForwardModelEvent::PunchForwardModelEvent(std::shared_ptr<Map::Map> map) : ModelEvent(map) {};

void PunchForwardModelEvent::_execute() {
    map->step(CharacterAction::PUNCH_FORWARD);
}
};
