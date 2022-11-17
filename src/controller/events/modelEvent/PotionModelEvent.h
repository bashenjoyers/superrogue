#pragma once

#include "model/map/Map.h"
#include "controller/events/ModelEvent.h"
#include "controller/CursorState.h"


namespace superrogue::controller::event {
class PotionModelEvent : public ModelEvent {
public:
    PotionModelEvent(std::shared_ptr<superrogue::map::Map> map, std::shared_ptr<superrogue::controller::CursorState> cursor_state); 
private:
    std::shared_ptr<superrogue::controller::CursorState> cursor_state;
    void _execute() override;
};
}
