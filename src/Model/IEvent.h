#pragma once

#include <memory>
#include <vector>

#include "Common/Observers.h"

namespace GameModel::Events {

class IEvent {
public:
    IEvent(std::shared_ptr<Map::World> map, std::shared_ptr<UIModel::CursorState> cursorState);
  virtual ~IEvent() {}

  void execute();
  void addObserver(std::shared_ptr<ModelObserver> observer);

protected:
  virtual void _execute() = 0;

protected:
    std::shared_ptr<Map::World> map;
    std::shared_ptr<UIModel::CursorState> cursorState;
private:
    void notify();
    std::vector<std::shared_ptr<ModelObserver>> observers;
};

} // namespace GameModel::Events
