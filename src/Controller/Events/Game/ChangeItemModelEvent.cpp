#include "ChangeItemModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace Controller::Events {
ChangeItemModelEvent::ChangeItemModelEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void ChangeItemModelEvent::_execute() {
  map->step(GameModel::CharacterAction::CHANGE_ITEM);
}
}; // namespace GameModel::Events
