#include "MoveEquipmentUpEvent.h"

void superrogue::controller::event::MoveEquipmentUpEvent::_execute() {
    cursorState->incrementEquipmentCursor();
}
