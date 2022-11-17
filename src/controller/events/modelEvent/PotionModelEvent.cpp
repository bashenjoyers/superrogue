#include "controller/events/modelEvent/PotionModelEvent.h"
#include "exceptions/exceptions.h"

using superrogue::map::Map;
using superrogue::map::MapInfo;
using std::shared_ptr;
using std::make_shared;
using superrogue::game_object::character::CharacterAction;;
using superrogue::controller::CursorState;
using superrogue::exception::EventException;


namespace superrogue::controller::event {
PotionModelEvent::PotionModelEvent(std::shared_ptr<superrogue::map::Map> map, std::shared_ptr<superrogue::controller::CursorState> cursor_state) : ModelEvent(map), cursor_state(cursor_state) {};

void PotionModelEvent::_execute() {
    size_t cursor_res = cursor_state->getPotionsCursor();
    switch (cursor_res)
    {
    case 0:
        map->step(CharacterAction::POTION_1);
        break;
    case 1:
        map->step(CharacterAction::POTION_2);
        break;
    case 2:
        map->step(CharacterAction::POTION_3);
        break;
    default:
        throw EventException("wrong potion pointer");
    }
}
};
