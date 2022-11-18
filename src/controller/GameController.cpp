#include "controller/GameController.h"

namespace superrogue::controller {

GameController::GameController(std::unique_ptr<EventProvider> provider) : ncursesApi(Ncurses::NcursesAPI::getInstance()),
                                                                          eventProvider(std::move(provider)) {}


void GameController::interact() {
    int userKey = ncursesApi->getKey();
    std::shared_ptr<IEvent> event = eventProvider->getEventByKey(userKey);
    event->execute();
}

void GameController::addUIObserver(std::shared_ptr<superrogue::view::UIObserver> obs) {
    eventProvider->addUIObserver(obs);
}

void GameController::addModelObserver(std::shared_ptr<superrogue::view::ModelObserver> obs) {
    eventProvider->addModelObserver(obs);
}

}
