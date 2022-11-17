#pragma once

#include "controller/events/UIEvent.h"

namespace superrogue::controller::event {

    class MoveEquipmentUpEvent : public UIEvent {
    private:
        virtual void _execute() override;
    };
}