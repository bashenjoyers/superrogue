#include "MovePotionDownEvent.h"

void superrogue::controller::event::MovePotionDownEvent::_execute() {
    cursorState->decrementPotionsCursor();
}
