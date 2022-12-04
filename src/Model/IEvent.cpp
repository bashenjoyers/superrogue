#include "IEvent.h"

void GameModel::Events::IEvent::execute() {
  _execute();
  notify();
}

void GameModel::Events::IEvent::notify() {
    for (auto observer: observers) {
        observer->handleEvent(std::make_shared<Map::MapInfo>(map->get_map_info()), cursorState);
    }
}

void GameModel::Events::IEvent::addObserver(std::shared_ptr<ModelObserver> observer) {
    observers.push_back(observer);
}

GameModel::Events::IEvent::IEvent(std::shared_ptr<Map::World> map, std::shared_ptr<UIModel::CursorState> cursorState) : map(map), cursorState(cursorState) {}
