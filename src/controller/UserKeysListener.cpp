#include "controller/UserKeysListener.h"

namespace superrogue::controller {
    std::shared_ptr<event::IEvent> UserKeysListener::onKeyPressed(int key) {
        std::shared_ptr<event::IEvent> event = eventProvider.getEventByKey(key);
        return event;
    }
}
