#pragma once

#include "UIEvent.h"

namespace GameModel::Events {

    class MoveEquipmentDownEvent : public UIEvent {
    public:
        MoveEquipmentDownEvent(std::shared_ptr<UIModel::CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}
