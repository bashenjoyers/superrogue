#pragma once

#include "controller/events/UIEvent.h"

namespace superrogue::controller::event {

    class MoveEquipmentDownEvent : public UIEvent {
    private:
        virtual void _execute() override;
    };
}
