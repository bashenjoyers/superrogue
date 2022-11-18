#include "GameController.h"
#include "Model/IEvent.h"

namespace Controller {

GameController::GameController(std::unique_ptr<EventProvider> provider) : ncursesApi(Ncurses::NcursesAPI::getInstance()),
                                                                          eventProvider(std::move(provider)) {}


void GameController::interact() {
    int userKey = ncursesApi->getKey();
    std::shared_ptr<GameModel::Events::IEvent> event = eventProvider->getEventByKey(userKey);
    event->execute();
}

void GameController::addUIObserver(std::shared_ptr<UIModelObserver> obs) {
    eventProvider->addUIObserver(obs);
}

void GameController::addModelObserver(std::shared_ptr<GameModelObserver> obs) {
    eventProvider->addModelObserver(obs);
}

}
