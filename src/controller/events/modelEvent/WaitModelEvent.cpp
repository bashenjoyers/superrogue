#include "controller/events/modelEvent/WaitModelEvent.h"

using superrogue::map::Map;
using superrogue::map::MapInfo;
using std::shared_ptr;
using std::make_shared;
using superrogue::game_object::character::CharacterAction;;


namespace superrogue::controller::event {
WaitModelEvent::WaitModelEvent(std::shared_ptr<superrogue::map::Map*> map) : ModelEvent(map) {};

void WaitModelEvent::_execute() {
    (*map)->step(CharacterAction::WAIT);
}
};
