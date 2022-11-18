#include "UIEvent.h"

GameModel::Events::UIEvent::UIEvent(std::shared_ptr<UIModel::CursorState> cursorState) {
    this->cursorState = std::move(cursorState);
}

void GameModel::Events::UIEvent::notify() {
    for (auto observer: observers) {
        observer->handleEvent(cursorState->getPotionsCursor(), cursorState->getEquipmentCursor());
    }
}

void GameModel::Events::UIEvent::addObserver(std::shared_ptr<UIModelObserver> observer) {
    observers.push_back(observer);
}
