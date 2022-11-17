#pragma once

#include <utility>

#include "controller/events/IEvent.h"
#include "controller/CursorState.h"

namespace superrogue::controller::event {

    class UIEvent : public IEvent {
    public:
        UIEvent(std::shared_ptr<CursorState> cursorState);

        void addObserver(std::shared_ptr<view::UIObserver> observer);

    protected:
        std::shared_ptr<CursorState> cursorState;

    private:
        virtual void notify() override;

        std::vector<std::shared_ptr<view::UIObserver>> observers;
    };

}