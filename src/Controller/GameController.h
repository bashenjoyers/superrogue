#pragma once

#include "Common/Ncurses/CursesAPI.h"
#include "Common/Observers.h"
#include "EventProvider.h"

namespace Controller {

class GameController {
public:
  GameController(std::unique_ptr<EventProvider> provider);
  void interact();

private:
  std::shared_ptr<Ncurses::NcursesAPI> ncursesApi;
  std::unique_ptr<EventProvider> eventProvider;
};
} // namespace Controller
