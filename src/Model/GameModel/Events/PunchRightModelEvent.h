#pragma once

#include "Model/IEvent.h"
#include "Model/GameModel/Map/World.h"

namespace GameModel::Events {
class PunchRightModelEvent : public IEvent {
public:
  PunchRightModelEvent(std::shared_ptr<Map::World> map, std::shared_ptr<UIModel::CursorState> cursorState);

private:
  void _execute() override;
};
} // namespace GameModel::Events
