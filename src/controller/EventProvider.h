#pragma once

#include <map>
#include "controller/CursorState.h"
#include "controller/events/IEvent.h"
#include "controller/events/uiEvent/MovePotionDownEvent.h"
#include "controller/events/uiEvent/MovePotionUpEvent.h"
#include "controller/events/uiEvent/MoveEquipmentDownEvent.h"
#include "controller/events/uiEvent/MoveEquipmentUpEvent.h"

using namespace superrogue::controller::event;

namespace superrogue::controller {

    class EventProvider {
    public:
        EventProvider(const std::shared_ptr<CursorState>& cursorState);
        std::shared_ptr<event::IEvent> getEventByKey(int key);

    private:
        std::map<int, std::shared_ptr<event::IEvent>> keyMapping;
    };
}
