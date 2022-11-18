#include "ModelEvent.h"

using std::make_shared;
using std::shared_ptr;

namespace GameModel::Events {

void ModelEvent::notify() {
  for (auto observer : observers) {
    shared_ptr<Map::MapInfo> map_info =
        make_shared<Map::MapInfo>(map->get_map_info());
    observer->handleEvent(map_info);
  }
}

ModelEvent::ModelEvent(shared_ptr<Map::Map> map) : map(map){};

void Events::ModelEvent::addObserver(shared_ptr<GameModelObserver> observer) {
  observers.push_back(observer);
}
}; // namespace GameModel::Events
