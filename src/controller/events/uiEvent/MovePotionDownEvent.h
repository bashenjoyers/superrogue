#pragma once

#include "controller/events/UIEvent.h"

namespace superrogue::controller::event {

    class MovePotionDownEvent : public UIEvent {
    public:
        MovePotionDownEvent(std::shared_ptr<CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}

