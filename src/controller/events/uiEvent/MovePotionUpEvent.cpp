#include "MovePotionUpEvent.h"

#include <utility>

superrogue::controller::event::MovePotionUpEvent::MovePotionUpEvent(std::shared_ptr<CursorState> cursorState) : UIEvent(
        std::move(cursorState)) {}

void superrogue::controller::event::MovePotionUpEvent::_execute() {
    cursorState->incrementPotionsCursor();
}
