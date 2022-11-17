#include "MoveEquipmentDownEvent.h"

void superrogue::controller::event::MoveEquipmentDownEvent::_execute() {
    cursorState->decrementEquipmentCursor();
}
