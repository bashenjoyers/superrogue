#pragma once

#include "Model/IEvent.h"
#include "Model/GameModel/Map/World.h"

namespace GameModel::Events {
class StepForwardModelEvent : public IEvent {
public:
  StepForwardModelEvent(std::shared_ptr<Map::World> map, std::shared_ptr<UIModel::CursorState> cursorState);

private:
  void _execute() override;
};
} // namespace GameModel::Events
