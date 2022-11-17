#include "controller/events/ModelEvent.h"

using superrogue::map::Map;
using superrogue::map::MapInfo;
using std::shared_ptr;
using std::make_shared;


namespace superrogue::controller::event {
void ModelEvent::notify() {
    for (auto observer: observers) {
        shared_ptr<MapInfo> map_info = make_shared<MapInfo>(map->get_map_info());
        observer->handleEvent(map_info);
    }
}

ModelEvent::ModelEvent(shared_ptr<superrogue::map::Map> map) : map(map) {}; 

void superrogue::controller::event::ModelEvent::addObserver(shared_ptr<view::ModelObserver> observer) {
    observers.push_back(observer);
}
};
