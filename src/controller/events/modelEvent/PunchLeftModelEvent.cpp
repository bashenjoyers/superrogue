#include "controller/events/modelEvent/PunchLeftModelEvent.h"

using superrogue::map::Map;
using superrogue::map::MapInfo;
using std::shared_ptr;
using std::make_shared;
using superrogue::game_object::character::CharacterAction;;


namespace superrogue::controller::event {
PunchLeftModelEvent::PunchLeftModelEvent(std::shared_ptr<superrogue::map::Map> map) : ModelEvent(map) {};

void PunchLeftModelEvent::map_action() {
    map->step(CharacterAction::PUNCH_LEFT);
}
};
