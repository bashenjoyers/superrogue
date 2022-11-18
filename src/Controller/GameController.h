#pragma once


#include "EventProvider.h"
#include "Common/Observers.h"
#include "Common/Ncurses/CursesAPI.h"

namespace Controller {

    class GameController {
    public:
        GameController(std::unique_ptr<EventProvider> provider);
        void interact();

        void addUIObserver(std::shared_ptr<UIModelObserver> obs);
        void addModelObserver(std::shared_ptr<GameModelObserver> obs);
    private:
        std::shared_ptr<Ncurses::NcursesAPI> ncursesApi;
        std::unique_ptr<EventProvider> eventProvider;
    };
}
