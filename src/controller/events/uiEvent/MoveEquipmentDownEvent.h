#pragma once

#include "controller/events/UIEvent.h"

namespace superrogue::controller::event {

    class MoveEquipmentDownEvent : public UIEvent {
    public:
        MoveEquipmentDownEvent(std::shared_ptr<CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}
