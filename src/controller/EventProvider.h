#pragma once

#include <map>
#include "controller/CursorState.h"
#include "controller/events/IEvent.h"
#include "controller/events/uiEvent/MovePotionDownEvent.h"
#include "controller/events/uiEvent/MovePotionUpEvent.h"
#include "controller/events/uiEvent/MoveEquipmentDownEvent.h"
#include "controller/events/uiEvent/MoveEquipmentUpEvent.h"
#include "controller/events/EmptyEvent.h"

using namespace superrogue::controller::event;

namespace superrogue::controller {

class EventProvider {
public:
    EventProvider(std::shared_ptr<CursorState> cursorState, std::shared_ptr<superrogue::map::Map*> map);
    std::shared_ptr<event::IEvent> getEventByKey(int key);

    void addUIObserver(std::shared_ptr<superrogue::view::UIObserver> obs);
    void addModelObserver(std::shared_ptr<superrogue::view::ModelObserver> obs);
private:
    std::map<int, std::shared_ptr<event::IEvent>> keyMapping;
    std::shared_ptr<event::EmptyEvent> emptyEvent = std::make_shared<event::EmptyEvent>();
};

}
