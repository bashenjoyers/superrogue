#include "PunchRightModelEvent.h"

using std::shared_ptr;
using std::make_shared;


namespace GameModel::Events {
PunchRightModelEvent::PunchRightModelEvent(std::shared_ptr<Map::Map> map) : ModelEvent(map) {};

void PunchRightModelEvent::_execute() {
    map->step(CharacterAction::PUNCH_RIGHT);
}
};
