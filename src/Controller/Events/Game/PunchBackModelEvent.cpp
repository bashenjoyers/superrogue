#include "PunchBackModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace Controller::Events {
PunchBackModelEvent::PunchBackModelEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
    : IEvent(map, cursorState){};

void PunchBackModelEvent::_execute() { map->step(GameModel::CharacterAction::PUNCH_BACK); }
}; // namespace GameModel::Events
