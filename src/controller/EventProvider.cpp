#include "controller/EventProvider.h"

namespace superrogue::controller {
    std::shared_ptr<event::IEvent> EventProvider::getEventByKey(int key) {
        return keyMapping[key];
    }
}
