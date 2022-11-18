#pragma once

#include "model/map/Map.h"
#include "controller/events/ModelEvent.h"


namespace superrogue::controller::event {
class ChangeItemModelEvent : public ModelEvent {
public:
    ChangeItemModelEvent(std::shared_ptr<superrogue::map::Map*> map); 
private:
    void _execute() override;
};
}
