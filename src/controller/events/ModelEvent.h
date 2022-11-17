#pragma once

#include "controller/events/IEvent.h"
#include "model/map/Map.h"


namespace superrogue::controller::event {
class ModelEvent : public IEvent {
public:
    void addObserver(std::shared_ptr<view::ModelObserver> observer);
    ModelEvent(std::shared_ptr<superrogue::map::Map> map);
protected:
    std::shared_ptr<superrogue::map::Map> map;
    virtual void map_action() = 0;
private:
    void notify() override;
    std::vector<std::shared_ptr<view::ModelObserver>> observers;
};
}
