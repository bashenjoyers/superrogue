#pragma once

#include <memory>

#include "Model/EmptyEvent.h"
#include "Model/GameModel/Map/Map.h"
#include "Model/IEvent.h"
#include "Model/UIModel/CursorState.h"

#include "Common/Observers.h"

namespace Controller {

class EventProvider {
public:
  EventProvider(std::shared_ptr<UIModel::CursorState> cursorState,
                std::shared_ptr<GameModel::Map::Map> map);
  std::shared_ptr<GameModel::Events::IEvent> getEventByKey(int key);

  void addUIObserver(std::shared_ptr<UIModelObserver> obs);
  void addModelObserver(std::shared_ptr<GameModelObserver> obs);

private:
  std::map<int, std::shared_ptr<GameModel::Events::IEvent>> keyMapping;
  std::shared_ptr<GameModel::Events::EmptyEvent> emptyEvent =
      std::make_shared<GameModel::Events::EmptyEvent>();
};

} // namespace Controller
