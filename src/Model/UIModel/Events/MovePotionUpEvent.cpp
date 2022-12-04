#include "MovePotionUpEvent.h"

#include <utility>

GameModel::Events::MovePotionUpEvent::MovePotionUpEvent(std::shared_ptr<Map::World> map, std::shared_ptr<UIModel::CursorState> cursorState) : IEvent(map, cursorState) {}

void GameModel::Events::MovePotionUpEvent::_execute() {
    cursorState->incrementPotionsCursor();
}
