#pragma once

#include <map>
#include "EventProvider.h"

using namespace superrogue::controller::event;

namespace superrogue::controller {

    class UserKeysListener {
        EventProvider eventProvider;
    public:
        std::shared_ptr<event::IEvent> onKeyPressed(int key);
    };
}
