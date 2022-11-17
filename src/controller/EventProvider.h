#pragma once

#include <map>
#include "IEvent.h"

using namespace superrogue::controller::event;

namespace superrogue::controller {

    class EventProvider {
    public:
        std::shared_ptr<event::IEvent> getEventByKey(int key);

    private:
        std::map<int, IEvent> keyMapping;
    };
}
