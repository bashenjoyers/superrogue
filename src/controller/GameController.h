#pragma once

#include "common/Ncurses/CursesAPI.h"
#include "view/Observers.h"

#include "controller/EventProvider.h"
#include "controller/CursorState.h"

#include "model/map/Map.h"

namespace superrogue::controller {

    class GameController {
    public:
        GameController(std::unique_ptr<EventProvider> provider);
        void interact();

        void addUIObserver(std::shared_ptr<superrogue::view::UIObserver> obs);
        void addModelObserver(std::shared_ptr<superrogue::view::ModelObserver> obs);
    private:
        std::shared_ptr<Ncurses::NcursesAPI> ncursesApi;
        std::unique_ptr<EventProvider> eventProvider;
    };
}
