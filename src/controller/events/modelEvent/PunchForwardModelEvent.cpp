#include "controller/events/modelEvent/PunchForwardModelEvent.h"

using superrogue::map::Map;
using superrogue::map::MapInfo;
using std::shared_ptr;
using std::make_shared;
using superrogue::game_object::character::CharacterAction;;


namespace superrogue::controller::event {
PunchForwardModelEvent::PunchForwardModelEvent(std::shared_ptr<superrogue::map::Map*> map) : ModelEvent(map) {};

void PunchForwardModelEvent::_execute() {
    (*map)->step(CharacterAction::PUNCH_FORWARD);
}
};
