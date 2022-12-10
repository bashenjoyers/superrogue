#pragma once

#include "Controller/Events/IEvent.h"

namespace Controller::Events {

    class MovePotionUpEvent : public IEvent {
    public:
        MovePotionUpEvent(std::shared_ptr<GameModel::GameManager> map, std::shared_ptr<UIModel::CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}
