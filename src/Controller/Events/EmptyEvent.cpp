#include "EmptyEvent.h"

namespace Controller::Events {

void EmptyEvent::_execute() {}

    EmptyEvent::EmptyEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState) : IEvent(map, cursorState) {}

} // namespace GameModel::Events