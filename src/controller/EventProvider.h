#pragma once

#include <map>
#include "IEvent.h"
using namespace superrogue::controller::event;

namespace superrogue::controller {

    class EventProvider {
        std::map<int, IEvent> keyMapping;
    public:
        std::shared_ptr<event::IEvent> getEventByKey(int key);
    };
}
