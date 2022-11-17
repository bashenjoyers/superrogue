#include "controller/EventProvider.h"

namespace superrogue::controller {

    EventProvider::EventProvider(const std::shared_ptr<CursorState>& cursorState) {
        keyMapping = {
                {'[', std::make_shared<MovePotionDownEvent>(cursorState)},
                {']', std::make_shared<MovePotionUpEvent>(cursorState)},
                {'-', std::make_shared<MoveEquipmentDownEvent>(cursorState)},
                {'=', std::make_shared<MoveEquipmentUpEvent>(cursorState)}
        };
    }

    std::shared_ptr<event::IEvent> EventProvider::getEventByKey(int key) {
        return keyMapping[key];
    }
}
