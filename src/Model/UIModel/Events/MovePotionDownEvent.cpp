#include "MovePotionDownEvent.h"

GameModel::Events::MovePotionDownEvent::MovePotionDownEvent(std::shared_ptr<Map::Map> map, std::shared_ptr<UIModel::CursorState> cursorState)
        : IEvent(map, cursorState) {}

void GameModel::Events::MovePotionDownEvent::_execute() {
    cursorState->decrementPotionsCursor();
}
