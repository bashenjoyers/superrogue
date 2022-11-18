#pragma once

#include <memory>
#include <vector>

#include "Common/Observers.h"

namespace GameModel::Events {

class IEvent {
public:
  virtual ~IEvent() {}

  void execute();

protected:
  virtual void _execute() = 0;
  virtual void notify() = 0;
};

} // namespace GameModel::Events
