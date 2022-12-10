#include "MovePotionDownEvent.h"

Controller::Events::MovePotionDownEvent::MovePotionDownEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState)
        : IEvent(map, cursorState) {}

void Controller::Events::MovePotionDownEvent::_execute() {
    cursorState->decrementPotionsCursor();
}
