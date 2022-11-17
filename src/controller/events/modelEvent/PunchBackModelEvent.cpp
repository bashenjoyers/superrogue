#include "controller/events/modelEvent/PunchBackModelEvent.h"

using superrogue::map::Map;
using superrogue::map::MapInfo;
using std::shared_ptr;
using std::make_shared;
using superrogue::game_object::character::CharacterAction;;


namespace superrogue::controller::event {
PunchBackModelEvent::PunchBackModelEvent(std::shared_ptr<superrogue::map::Map> map) : ModelEvent(map) {};

void PunchBackModelEvent::map_action() {
    map->step(CharacterAction::PUNCH_BACK);
}
};
