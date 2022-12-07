#pragma once

#include "Model/IEvent.h"

namespace GameModel::Events {

class EmptyEvent : public IEvent {
public:
    EmptyEvent(std::shared_ptr<GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState);
private:
  virtual void _execute() override;
};

} // namespace GameModel::Events