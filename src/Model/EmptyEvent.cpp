#include "EmptyEvent.h"

namespace GameModel::Events {

void EmptyEvent::_execute() {}

    EmptyEvent::EmptyEvent(std::shared_ptr<GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState) : IEvent(map, cursorState) {}

} // namespace GameModel::Events