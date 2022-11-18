#pragma once

#include <vector>
#include <memory>

#include "common/Observers.h"

namespace superrogue::controller::event {

class IEvent {
public:
    virtual ~IEvent() {}

    void execute();

protected:
    virtual void _execute() = 0;
    virtual void notify() = 0;
};

}
