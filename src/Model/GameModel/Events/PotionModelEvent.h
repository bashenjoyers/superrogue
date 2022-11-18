#pragma once

#include "Model/GameModel/Events/ModelEvent.h"
#include "Model/GameModel/Map/Map.h"
#include "Model/UIModel/CursorState.h"

namespace GameModel::Events {
class PotionModelEvent : public ModelEvent {
public:
  PotionModelEvent(std::shared_ptr<Map::Map> map,
                   std::shared_ptr<UIModel::CursorState> cursor_state);

private:
  std::shared_ptr<UIModel::CursorState> cursor_state;
  void _execute() override;
};
} // namespace GameModel::Events
