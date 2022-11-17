#include "controller/GameController.h"

namespace superrogue::controller {

    void GameController::interact() {
        int userKey = ncursesApi->getKey();
        std::shared_ptr<IEvent> event = keysListener->onKeyPressed(userKey);
        event->execute();
    }
}
