#pragma once

#include "Common/Ncurses/CursesAPI.h"
#include "View/Observers.h"
#include "EventProvider.h"

#include "View/Curses/CursesRenderer.h"

namespace Controller {

/**
 * @brief a class that interacts with user input data
 */
class GameController {
public:

  /**
  * @brief constructs a new Game Controller object
  *
  *
  */
  GameController();

  /**
   * @brief method to start app execution
   */
  void run();

private:
  void interact();

  std::shared_ptr<Ncurses::NcursesAPI> ncursesApi;
  std::unique_ptr<EventProvider> eventProvider;

  std::shared_ptr<GameModel::GameManager> gm;
  std::shared_ptr<View::CursesRenderer> renderer;

  GameModel::Map::MapOptions mapOptions = {
      .height = 30,
      .width = 60,
  };
};
} // namespace Controller
