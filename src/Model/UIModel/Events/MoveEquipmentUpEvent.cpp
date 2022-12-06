#include "MoveEquipmentUpEvent.h"

#include <utility>

GameModel::Events::MoveEquipmentUpEvent::MoveEquipmentUpEvent(std::shared_ptr<GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
        : IEvent(map, cursorState) {}

void GameModel::Events::MoveEquipmentUpEvent::_execute() {
    cursorState->incrementEquipmentCursor();
}
