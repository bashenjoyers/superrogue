#include "controller/events/modelEvent/ChangeItemModelEvent.h"

using superrogue::map::Map;
using superrogue::map::MapInfo;
using std::shared_ptr;
using std::make_shared;
using superrogue::game_object::character::CharacterAction;;


namespace superrogue::controller::event {
ChangeItemModelEvent::ChangeItemModelEvent(std::shared_ptr<superrogue::map::Map> map) : ModelEvent(map) {};

void ChangeItemModelEvent::map_action() {
    map->step(CharacterAction::CHANGE_ITEM);
}
};
