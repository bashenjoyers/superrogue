#pragma once

#include "view/Curses/CursesAPI.h"
#include "controller/UserKeysListener.h"

namespace superrogue::controller {

    class GameController {
    public:
        void interact();

    private:
        std::shared_ptr<Ncurses::NcursesAPI> ncursesApi = Ncurses::NcursesAPI::getInstance();
        std::shared_ptr<UserKeysListener> keysListener = std::make_shared<UserKeysListener>();
    };
}
