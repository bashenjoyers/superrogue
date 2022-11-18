#include "MovePotionDownEvent.h"

GameModel::Events::MovePotionDownEvent::MovePotionDownEvent(std::shared_ptr<UIModel::CursorState> cursorState)
        : UIEvent(std::move(cursorState)) {}

void GameModel::Events::MovePotionDownEvent::_execute() {
    cursorState->decrementPotionsCursor();
}
