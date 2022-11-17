#pragma once

#include "controller/events/UIEvent.h"

namespace superrogue::controller::event {

    class MovePotionUpEvent : public UIEvent {
    public:
        MovePotionUpEvent(std::shared_ptr<CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}
