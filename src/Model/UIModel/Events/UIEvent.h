#pragma once

#include <utility>

#include "Model/IEvent.h"
#include "Model/UIModel/CursorState.h"

namespace GameModel::Events {

    class UIEvent : public IEvent {
    public:
        UIEvent(std::shared_ptr<UIModel::CursorState> cursorState);

        void addObserver(std::shared_ptr<UIModelObserver> observer);

    protected:
        std::shared_ptr<UIModel::CursorState> cursorState;

    private:
        virtual void notify() override;

        std::vector<std::shared_ptr<UIModelObserver>> observers;
    };

}