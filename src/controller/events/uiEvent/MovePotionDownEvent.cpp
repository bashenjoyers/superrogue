#include "MovePotionDownEvent.h"

superrogue::controller::event::MovePotionDownEvent::MovePotionDownEvent(std::shared_ptr<CursorState> cursorState)
        : UIEvent(std::move(cursorState)) {}

void superrogue::controller::event::MovePotionDownEvent::_execute() {
    cursorState->decrementPotionsCursor();
}
