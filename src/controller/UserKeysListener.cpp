#include "controller/UserKeysListener.h"

namespace superrogue::controller {

    UserKeysListener::UserKeysListener(const std::shared_ptr<CursorState>& cursorState) {
        this->eventProvider = std::make_shared<EventProvider>(cursorState);
    }

    std::shared_ptr<event::IEvent> UserKeysListener::onKeyPressed(int key) {
        std::shared_ptr<event::IEvent> event = eventProvider->getEventByKey(key);
        return event;
    }
}
