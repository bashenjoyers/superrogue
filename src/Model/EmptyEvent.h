#pragma once

#include "Model/IEvent.h"

namespace GameModel::Events {

class EmptyEvent : public IEvent {
private:
  virtual void _execute() override;
  virtual void notify() override;
};

} // namespace GameModel::Events