#include "ChangeWeaponModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {
ChangeWeaponModelEvent::ChangeWeaponModelEvent(std::shared_ptr<GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void ChangeWeaponModelEvent::_execute() {
  map->step(CharacterAction::CHANGE_WEAPON);
}
}; // namespace GameModel::Events
