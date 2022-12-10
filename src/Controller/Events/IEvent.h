#pragma once

#include <memory>
#include <vector>

#include "View/Observers.h"
#include "Model/GameModel/GameManager.h"
#include "Model/UIModel/CursorState.h"

namespace Controller::Events {

class IEvent {
public:
    IEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState);
  virtual ~IEvent() {}

  void execute();
  void addObserver(std::shared_ptr<RenderDataObserver> observer);

protected:
  virtual void _execute() = 0;

protected:
    std::shared_ptr<GameModel::GameManager> map;
    std::shared_ptr<UIModel::CursorState> cursorState;
private:
    void notify();
    std::vector<std::shared_ptr<RenderDataObserver>> observers;
};

} // namespace GameModel::Events
