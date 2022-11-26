#include "MoveEquipmentDownEvent.h"

GameModel::Events::MoveEquipmentDownEvent::MoveEquipmentDownEvent(std::shared_ptr<Map::Map> map, std::shared_ptr<UIModel::CursorState> cursorState)
        : IEvent(map, cursorState) {}

void GameModel::Events::MoveEquipmentDownEvent::_execute() {
    cursorState->decrementEquipmentCursor();
}
