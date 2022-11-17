#pragma once

#include <map>
#include "EventProvider.h"
#include "CursorState.h"

using namespace superrogue::controller::event;

namespace superrogue::controller {

    class UserKeysListener {
    public:
        UserKeysListener(const std::shared_ptr<CursorState>& cursorState);
        std::shared_ptr<event::IEvent> onKeyPressed(int key);

    private:
        std::shared_ptr<EventProvider> eventProvider;
        std::shared_ptr<CursorState> cursorState;
    };
}
