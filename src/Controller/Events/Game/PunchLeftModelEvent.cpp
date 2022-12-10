#include "PunchLeftModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace Controller::Events {
PunchLeftModelEvent::PunchLeftModelEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void PunchLeftModelEvent::_execute() { map->step(GameModel::CharacterAction::PUNCH_LEFT); }
}; // namespace GameModel::Events
