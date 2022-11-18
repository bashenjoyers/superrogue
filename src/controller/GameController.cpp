#include "controller/GameController.h"

namespace superrogue::controller {

GameController::GameController(std::shared_ptr<superrogue::map::Map*> map) : ncursesApi(Ncurses::NcursesAPI::getInstance()),
                                                                            cursorState(std::make_shared<CursorState>()) {
    eventProvider = std::make_shared<EventProvider>(cursorState, map);
}


void GameController::interact() {
    int userKey = ncursesApi->getKey();
    std::shared_ptr<IEvent> event = eventProvider->getEventByKey(userKey);
    event->execute();
}

std::shared_ptr<CursorState> GameController::getCursorState() {
    return cursorState;
}

void GameController::addUIObserver(std::shared_ptr<superrogue::view::UIObserver> obs) {
    eventProvider->addUIObserver(obs);
}

void GameController::addModelObserver(std::shared_ptr<superrogue::view::ModelObserver> obs) {
    eventProvider->addModelObserver(obs);
}

}
