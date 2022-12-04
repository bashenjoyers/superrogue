#pragma once

#include "Model/IEvent.h"
#include "Model/GameModel/Map/World.h"
#include "Model/UIModel/CursorState.h"

namespace GameModel::Events {
class PotionModelEvent : public IEvent {
public:
  PotionModelEvent(std::shared_ptr<Map::World> map,
                   std::shared_ptr<UIModel::CursorState> cursor_state);

private:
  void _execute() override;
};
} // namespace GameModel::Events
