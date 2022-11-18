#pragma once

#include "UIEvent.h"

namespace GameModel::Events {

    class MovePotionUpEvent : public UIEvent {
    public:
        MovePotionUpEvent(std::shared_ptr<UIModel::CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}
