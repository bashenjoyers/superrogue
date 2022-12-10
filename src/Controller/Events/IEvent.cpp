#include "IEvent.h"
#include "../ModelViewDataConverter.h"

void Controller::Events::IEvent::execute() {
  _execute();
  notify();
}

void Controller::Events::IEvent::notify() {
    ModelViewDataConverter conv;
    RenderData data = conv.convert(map->getMapInfo(), *cursorState);
    for (const auto& observer: observers) {
        observer->handleEvent(data);
    }
}

void Controller::Events::IEvent::addObserver(std::shared_ptr<RenderDataObserver> observer) {
    observers.push_back(observer);
}

Controller::Events::IEvent::IEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState) : map(map), cursorState(cursorState) {}
