#pragma once

#include "Model/IEvent.h"
#include "Model/GameModel/Map/Map.h"

namespace GameModel::Events {
class StepBackModelEvent : public IEvent {
public:
  StepBackModelEvent(std::shared_ptr<Map::Map> map, std::shared_ptr<UIModel::CursorState> cursorState);

private:
  void _execute() override;
};
} // namespace GameModel::Events
