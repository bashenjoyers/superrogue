#pragma once

#include "Model/GameModel/Map/Map.h"
#include "Model/IEvent.h"
#include <memory>

namespace GameModel::Events {
class ModelEvent : public IEvent {
public:
  void addObserver(std::shared_ptr<GameModelObserver> observer);
  ModelEvent(std::shared_ptr<Map::Map> map);

protected:
  std::shared_ptr<Map::Map> map;

private:
  void notify() override;
  std::vector<std::shared_ptr<GameModelObserver>> observers;
};
} // namespace GameModel::Events
