#pragma once

#include <memory>

#include "Model/EmptyEvent.h"
#include "Model/GameModel/Map/Map.h"
#include "Model/IEvent.h"
#include "Model/UIModel/CursorState.h"

#include "Common/Observers.h"

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
                std::shared_ptr<GameModel::Map::Map> map);
  /**
  * @brief provides event by user's key
  *
  * @param key - represents user's key
  * @return shared_ptr<IEvent> - event for user's key
  */
  std::shared_ptr<GameModel::Events::IEvent> getEventByKey(int key);

  /**
  * @brief adds observer for events
  *
  * @param obs - represents observer
  */
  void addObserver(std::shared_ptr<ModelObserver> obs);

private:
  std::map<int, std::shared_ptr<GameModel::Events::IEvent>> keyMapping;
  std::shared_ptr<GameModel::Events::EmptyEvent> emptyEvent;
};

} // namespace Controller
