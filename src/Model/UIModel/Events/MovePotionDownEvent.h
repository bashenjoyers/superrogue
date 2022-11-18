#pragma once

#include "UIEvent.h"

namespace GameModel::Events {

    class MovePotionDownEvent : public UIEvent {
    public:
        MovePotionDownEvent(std::shared_ptr<UIModel::CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}

