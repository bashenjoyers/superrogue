#pragma once

#include "Model/IEvent.h"
#include "Model/GameModel/Map/Map.h"
#include "Model/UIModel/CursorState.h"

namespace GameModel::Events {
class StepRightModelEvent : public IEvent {
public:
  StepRightModelEvent(std::shared_ptr<Map::Map> map, std::shared_ptr<UIModel::CursorState> cursorState);

private:
  void _execute() override;
};
} // namespace GameModel::Events
