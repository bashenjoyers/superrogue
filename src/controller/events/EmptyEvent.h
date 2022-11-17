#pragma once

#include "IEvent.h"

namespace superrogue::controller::event {

class EmptyEvent : public IEvent {
private:
    virtual void _execute() override;
    virtual void notify() override;
};

}