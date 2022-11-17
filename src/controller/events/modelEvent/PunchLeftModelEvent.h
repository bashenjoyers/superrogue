#pragma once

#include "model/map/Map.h"
#include "controller/events/ModelEvent.h"


namespace superrogue::controller::event {
class PunchLeftModelEvent : public ModelEvent {
public:
    PunchLeftModelEvent(std::shared_ptr<superrogue::map::Map> map); 
private:
    void map_action() override;
};
}
