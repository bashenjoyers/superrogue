#include "ChangeWeaponModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace Controller::Events {
ChangeWeaponModelEvent::ChangeWeaponModelEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void ChangeWeaponModelEvent::_execute() {
  map->step(GameModel::CharacterAction::CHANGE_WEAPON);
}
}; // namespace GameModel::Events
