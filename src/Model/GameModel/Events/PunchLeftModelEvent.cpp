#include "PunchLeftModelEvent.h"

using std::shared_ptr;
using std::make_shared;


namespace GameModel::Events {
PunchLeftModelEvent::PunchLeftModelEvent(std::shared_ptr<Map::Map> map) : ModelEvent(map) {};

void PunchLeftModelEvent::_execute() {
    map->step(CharacterAction::PUNCH_LEFT);
}
};
