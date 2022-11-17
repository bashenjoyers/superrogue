#include "controller/events/modelEvent/PunchRightModelEvent.h"

using superrogue::map::Map;
using superrogue::map::MapInfo;
using std::shared_ptr;
using std::make_shared;
using superrogue::game_object::character::CharacterAction;;


namespace superrogue::controller::event {
PunchRightModelEvent::PunchRightModelEvent(std::shared_ptr<superrogue::map::Map> map) : ModelEvent(map) {};

void PunchRightModelEvent::_execute() {
    map->step(CharacterAction::PUNCH_RIGHT);
}
};
