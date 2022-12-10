#pragma once

#include "Controller/Events/IEvent.h"
#include "Model/GameModel/Map/World.h"

namespace Controller::Events {
class PunchForwardModelEvent : public IEvent {
public:
  PunchForwardModelEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState);

private:
  void _execute() override;
};
} // namespace GameModel::Events
