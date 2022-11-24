#pragma once

#include "Model/IEvent.h"
#include "Model/GameModel/Map/Map.h"

namespace GameModel::Events {
class ChangeWeaponModelEvent : public IEvent {
public:
  ChangeWeaponModelEvent(std::shared_ptr<Map::Map> map, std::shared_ptr<UIModel::CursorState> cursorState);

private:
  void _execute() override;
};
} // namespace GameModel::Events
