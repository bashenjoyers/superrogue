#include "ChangeItemModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
ChangeItemModelEvent::ChangeItemModelEvent(std::shared_ptr<Map::World> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void ChangeItemModelEvent::_execute() {
  map->step(CharacterAction::CHANGE_ITEM);
}
}; // namespace GameModel::Events
