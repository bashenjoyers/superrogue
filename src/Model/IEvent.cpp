#include "IEvent.h"

void GameModel::Events::IEvent::execute() {
    _execute();
    notify();
}

