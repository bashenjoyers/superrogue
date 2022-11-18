#pragma once

#include "model/map/Map.h"
#include "controller/events/ModelEvent.h"


namespace superrogue::controller::event {
class StepRightModelEvent : public ModelEvent {
public:
    StepRightModelEvent(std::shared_ptr<superrogue::map::Map*> map); 
private:
    void _execute() override;
};
}
