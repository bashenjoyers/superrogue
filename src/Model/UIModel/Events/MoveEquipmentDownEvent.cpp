#include "MoveEquipmentDownEvent.h"

#include <utility>

GameModel::Events::MoveEquipmentDownEvent::MoveEquipmentDownEvent(std::shared_ptr<UIModel::CursorState> cursorState)
        : UIEvent(std::move(cursorState)) {}

void GameModel::Events::MoveEquipmentDownEvent::_execute() {
    cursorState->decrementEquipmentCursor();
}
