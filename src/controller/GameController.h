#pragma once

#include "view/Curses/CursesAPI.h"
#include "controller/UserKeysListener.h"

namespace superrogue::controller {

    class GameController {
        std::shared_ptr<Ncurses::NcursesAPI> ncursesApi = Ncurses::NcursesAPI::getInstance();
        std::shared_ptr<UserKeysListener> keysListener = std::make_shared<UserKeysListener>();
    public:
        void interact();
    };
}
