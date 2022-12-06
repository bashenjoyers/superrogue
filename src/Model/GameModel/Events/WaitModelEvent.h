#pragma once

#include "Model/IEvent.h"
#include "Model/GameModel/Map/World.h"
#include "Model/UIModel/CursorState.h"

namespace GameModel::Events {
class WaitModelEvent : public IEvent {
public:
  WaitModelEvent(std::shared_ptr<GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState);

private:
  void _execute() override;
};
} // namespace GameModel::Events
