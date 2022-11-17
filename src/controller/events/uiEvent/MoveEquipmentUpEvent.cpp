#include "MoveEquipmentUpEvent.h"

#include <utility>

superrogue::controller::event::MoveEquipmentUpEvent::MoveEquipmentUpEvent(std::shared_ptr<CursorState> cursorState)
        : UIEvent(std::move(cursorState)) {}

void superrogue::controller::event::MoveEquipmentUpEvent::_execute() {
    cursorState->incrementEquipmentCursor();
}
