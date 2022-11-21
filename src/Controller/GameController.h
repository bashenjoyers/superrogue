#pragma once

#include "Common/Ncurses/CursesAPI.h"
#include "Common/Observers.h"
#include "EventProvider.h"

namespace Controller {

/**
 * @brief a class that interacts with user input data
 */
class GameController {
public:

  /**
  * @brief constructs a new Game Controller object
  *
  * @param provider - provides event to execute after user's key pressed
  */
  GameController(std::unique_ptr<EventProvider> provider);

  /**
  * @brief method to handle a single user's key
  */
  void interact();

  /**
  * @brief adds observer for UI events
  *
  * @param obs - observer to add
  */
  void addUIObserver(std::shared_ptr<UIModelObserver> obs);

  /**
  * @brief adds observer for Model events
  *
  * @param obs - observer to add
  */
  void addModelObserver(std::shared_ptr<GameModelObserver> obs);

private:
  std::shared_ptr<Ncurses::NcursesAPI> ncursesApi;
  std::unique_ptr<EventProvider> eventProvider;
};
} // namespace Controller
