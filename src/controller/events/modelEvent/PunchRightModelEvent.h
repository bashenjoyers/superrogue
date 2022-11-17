#pragma once

#include "model/map/Map.h"
#include "controller/events/ModelEvent.h"


namespace superrogue::controller::event {
class PunchRightModelEvent : public ModelEvent {
public:
    PunchRightModelEvent(std::shared_ptr<superrogue::map::Map> map); 
private:
    void _execute() override;
};
}
