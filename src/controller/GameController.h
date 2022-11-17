#pragma once

#include "view/Curses/CursesAPI.h"
#include "controller/UserKeysListener.h"
#include "controller/CursorState.h"

namespace superrogue::controller {

    class GameController {
    public:
        void interact();
        std::shared_ptr<CursorState> getCursorState();
    private:
        std::shared_ptr<Ncurses::NcursesAPI> ncursesApi = Ncurses::NcursesAPI::getInstance();
        std::shared_ptr<UserKeysListener> keysListener = std::make_shared<UserKeysListener>();
        std::shared_ptr<CursorState> cursorState = std::make_shared<CursorState>();
    };
}
