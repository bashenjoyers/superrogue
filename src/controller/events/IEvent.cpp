#include "IEvent.h"

void superrogue::controller::event::IEvent::execute() {
    _execute();
    notify();
}

