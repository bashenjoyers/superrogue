#include "MoveEquipmentDownEvent.h"

Controller::Events::MoveEquipmentDownEvent::MoveEquipmentDownEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
        : IEvent(map, cursorState) {}

void Controller::Events::MoveEquipmentDownEvent::_execute() {
    cursorState->decrementEquipmentCursor();
}
