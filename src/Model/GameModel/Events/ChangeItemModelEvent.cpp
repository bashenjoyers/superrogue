#include "ChangeItemModelEvent.h"

using std::shared_ptr;
using std::make_shared;


namespace GameModel::Events {
ChangeItemModelEvent::ChangeItemModelEvent(std::shared_ptr<Map::Map> map) : ModelEvent(map) {};

void ChangeItemModelEvent::_execute() {
    map->step(CharacterAction::CHANGE_ITEM);
}
};
