#pragma once

#include "Model/IEvent.h"

namespace GameModel::Events {

    class MovePotionUpEvent : public IEvent {
    public:
        MovePotionUpEvent(std::shared_ptr<Map::Map> map, std::shared_ptr<UIModel::CursorState> cursorState);
    private:
        virtual void _execute() override;
    };
}
