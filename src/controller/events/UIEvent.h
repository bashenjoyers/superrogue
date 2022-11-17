#pragma once

#include "controller/events/IEvent.h"

namespace superrogue::controller::event {

class UIEvent : public IEvent {
public:
    void addObserver(std::shared_ptr<view::UIObserver> observer);

private:
    virtual void notify() override;

    std::vector<std::shared_ptr<view::UIObserver>> observers;

    // todo std::shared_ptr<....>
};

}