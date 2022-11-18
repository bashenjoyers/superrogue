#pragma once

#include "Model/GameModel/Events/ModelEvent.h"
#include "Model/GameModel/Map/Map.h"

namespace GameModel::Events {
class PunchRightModelEvent : public ModelEvent {
public:
  PunchRightModelEvent(std::shared_ptr<Map::Map> map);

private:
  void _execute() override;
};
} // namespace GameModel::Events
