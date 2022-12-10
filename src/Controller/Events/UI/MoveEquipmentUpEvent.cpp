#include "MoveEquipmentUpEvent.h"

#include <utility>

Controller::Events::MoveEquipmentUpEvent::MoveEquipmentUpEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
        : IEvent(map, cursorState) {}

void Controller::Events::MoveEquipmentUpEvent::_execute() {
    cursorState->incrementEquipmentCursor();
}
