#include "MoveEquipmentUpEvent.h"

#include <utility>

GameModel::Events::MoveEquipmentUpEvent::MoveEquipmentUpEvent(std::shared_ptr<UIModel::CursorState> cursorState)
        : UIEvent(std::move(cursorState)) {}

void GameModel::Events::MoveEquipmentUpEvent::_execute() {
    cursorState->incrementEquipmentCursor();
}
