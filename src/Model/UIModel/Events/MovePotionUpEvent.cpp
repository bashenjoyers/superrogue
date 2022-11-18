#include "MovePotionUpEvent.h"

#include <utility>

GameModel::Events::MovePotionUpEvent::MovePotionUpEvent(std::shared_ptr<UIModel::CursorState> cursorState) : UIEvent(
        std::move(cursorState)) {}

void GameModel::Events::MovePotionUpEvent::_execute() {
    cursorState->incrementPotionsCursor();
}
