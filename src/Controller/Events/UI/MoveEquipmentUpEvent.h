#pragma once

#include "Controller/Events/IEvent.h"

namespace Controller::Events {

    class MoveEquipmentUpEvent : public IEvent {
    public:
        MoveEquipmentUpEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}