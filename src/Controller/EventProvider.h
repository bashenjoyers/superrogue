#pragma once

#include <memory>

#include "Controller/Events/EmptyEvent.h"
#include "Model/GameModel/Map/World.h"
#include "Controller/Events/IEvent.h"
#include "Model/UIModel/CursorState.h"

#include "View/Observers.h"

namespace Controller {

/**
 * @brief a class that provides event by key
 */
class EventProvider {
public:
  /**
  * @brief constructs a new Event Provider object
  *
  * @param cursorState - represents state of user's cursor
  * @param map - represents game map
  */
  EventProvider(std::shared_ptr<UIModel::CursorState> cursorState,
                std::shared_ptr<GameModel::GameManager> map);
  /**
  * @brief provides event by user's key
  *
  * @param key - represents user's key
  * @return shared_ptr<IEvent> - event for user's key
  */
  std::shared_ptr<Events::IEvent> getEventByKey(int key);

  /**
  * @brief adds observer for events
  *
  * @param obs - represents observer
  */
  void addObserver(std::shared_ptr<RenderDataObserver> obs);

private:
  std::map<int, std::shared_ptr<Events::IEvent>> keyMapping;
  std::shared_ptr<Events::EmptyEvent> emptyEvent;
};

} // namespace Controller
