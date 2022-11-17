#pragma once

#include <map>
#include "EventProvider.h"

using namespace superrogue::controller::event;

namespace superrogue::controller {

    class UserKeysListener {
    public:
        std::shared_ptr<event::IEvent> onKeyPressed(int key);

    private:
        EventProvider eventProvider;
    };
}
