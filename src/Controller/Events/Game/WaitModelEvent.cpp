#include "WaitModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace Controller::Events {
WaitModelEvent::WaitModelEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void WaitModelEvent::_execute() { map->step(GameModel::CharacterAction::WAIT); }
}; // namespace GameModel::Events
