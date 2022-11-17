#include "MovePotionUpEvent.h"

void superrogue::controller::event::MovePotionUpEvent::_execute() {
    cursorState->incrementPotionsCursor();
}
