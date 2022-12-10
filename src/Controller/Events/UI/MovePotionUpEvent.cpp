#include "MovePotionUpEvent.h"

#include <utility>

Controller::Events::MovePotionUpEvent::MovePotionUpEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState) : IEvent(map, cursorState) {}

void Controller::Events::MovePotionUpEvent::_execute() {
    cursorState->incrementPotionsCursor();
}
