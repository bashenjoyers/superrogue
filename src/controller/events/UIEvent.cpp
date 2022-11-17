#include "controller/events/UIEvent.h"

void superrogue::controller::event::UIEvent::notify() {
    for (auto observer: observers) {
        //observer->handleEvent();
    }
}

void superrogue::controller::event::UIEvent::addObserver(std::shared_ptr<view::UIObserver> observer) {
    observers.push_back(observer);
}
