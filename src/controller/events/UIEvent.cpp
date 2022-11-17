#include "controller/events/UIEvent.h"

superrogue::controller::event::UIEvent::UIEvent(std::shared_ptr<CursorState> cursorState) {
    this->cursorState = std::move(cursorState);
}

void superrogue::controller::event::UIEvent::notify() {
    for (auto observer: observers) {
        observer->handleEvent(cursorState->getPotionsCursor(), cursorState->getEquipmentCursor());
    }
}

void superrogue::controller::event::UIEvent::addObserver(std::shared_ptr<view::UIObserver> observer) {
    observers.push_back(observer);
}
