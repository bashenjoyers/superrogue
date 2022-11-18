#pragma once

#include "view/Curses/CursesAPI.h"
#include "view/Observers.h"

#include "controller/EventProvider.h"
#include "controller/CursorState.h"

#include "model/map/Map.h"

namespace superrogue::controller {

    class GameController {
    public:
        GameController(std::shared_ptr<superrogue::map::Map*> map);
        void interact();
        std::shared_ptr<CursorState> getCursorState();

        void addUIObserver(std::shared_ptr<superrogue::view::UIObserver> obs);
        void addModelObserver(std::shared_ptr<superrogue::view::ModelObserver> obs);
    private:
        std::shared_ptr<Ncurses::NcursesAPI> ncursesApi;
        std::shared_ptr<CursorState> cursorState;
        std::shared_ptr<EventProvider> eventProvider;
    };
}
