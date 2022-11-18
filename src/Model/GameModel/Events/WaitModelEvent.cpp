#include "WaitModelEvent.h"

using std::shared_ptr;
using std::make_shared;


namespace GameModel::Events {
WaitModelEvent::WaitModelEvent(std::shared_ptr<Map::Map> map) : ModelEvent(map) {};

void WaitModelEvent::_execute() {
    map->step(CharacterAction::WAIT);
}
};
