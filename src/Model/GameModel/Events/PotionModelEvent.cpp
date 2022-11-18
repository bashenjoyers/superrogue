#include "PotionModelEvent.h"
#include "Model/Exceptions/exceptions.h"

#include <memory>

using std::shared_ptr;
using std::make_shared;


namespace GameModel::Events {
PotionModelEvent::PotionModelEvent(std::shared_ptr<Map::Map> map, std::shared_ptr<UIModel::CursorState> cursor_state) : ModelEvent(map), cursor_state(cursor_state) {};

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
