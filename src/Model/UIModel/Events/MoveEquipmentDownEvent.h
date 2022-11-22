#pragma once

#include "Model/IEvent.h"

namespace GameModel::Events {

    class MoveEquipmentDownEvent : public IEvent {
    public:
        MoveEquipmentDownEvent(std::shared_ptr<Map::Map> map, std::shared_ptr<UIModel::CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}
