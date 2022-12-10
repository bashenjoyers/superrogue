#include "GameController.h"
#include "Controller/Events/IEvent.h"

namespace Controller {

GameController::GameController()
    : ncursesApi(Ncurses::NcursesAPI::getInstance()) {
  std::shared_ptr<UIModel::CursorState> cs = std::make_shared<UIModel::CursorState>();

  gm = std::make_shared<GameModel::GameManager>(mapOptions);
  eventProvider = std::make_unique<EventProvider>(cs, gm);
  renderer = std::make_shared<View::CursesRenderer>();
  eventProvider->addObserver(renderer);
}

void GameController::interact() {
  int userKey = ncursesApi->getKey();
  std::shared_ptr<Events::IEvent> event =
      eventProvider->getEventByKey(userKey);
  event->execute();
}

void GameController::run() {
  while (true) {
    interact();
    if (gm->isOver()) return;
  }
}

} // namespace Controller
