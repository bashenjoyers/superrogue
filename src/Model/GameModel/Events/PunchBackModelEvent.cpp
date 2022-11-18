#include "PunchBackModelEvent.h"

using std::shared_ptr;
using std::make_shared;


namespace GameModel::Events {
PunchBackModelEvent::PunchBackModelEvent(std::shared_ptr<Map::Map> map) : ModelEvent(map) {};

void PunchBackModelEvent::_execute() {
    map->step(CharacterAction::PUNCH_BACK);
}
};
