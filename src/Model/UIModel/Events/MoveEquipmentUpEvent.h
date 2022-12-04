#pragma once

#include "Model/IEvent.h"

namespace GameModel::Events {

    class MoveEquipmentUpEvent : public IEvent {
    public:
        MoveEquipmentUpEvent(std::shared_ptr<Map::World> map, std::shared_ptr<UIModel::CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}