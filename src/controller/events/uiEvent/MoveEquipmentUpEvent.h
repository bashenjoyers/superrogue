#pragma once

#include "controller/events/UIEvent.h"

namespace superrogue::controller::event {

    class MoveEquipmentUpEvent : public UIEvent {
    public:
        MoveEquipmentUpEvent(std::shared_ptr<CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}