#include "MoveEquipmentDownEvent.h"

#include <utility>

superrogue::controller::event::MoveEquipmentDownEvent::MoveEquipmentDownEvent(std::shared_ptr<CursorState> cursorState)
        : UIEvent(std::move(cursorState)) {}

void superrogue::controller::event::MoveEquipmentDownEvent::_execute() {
    cursorState->decrementEquipmentCursor();
}
