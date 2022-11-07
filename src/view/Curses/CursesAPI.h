#pragma once

#include <ncurses.h>
#include <memory>

namespace NCurses {

class Ncurses;

class NcursesWindow {
public:
    void drawElement(char c, size_t x, size_t y);

private:
    NcursesWindow(WINDOW *_win, size_t h, size_t w, size_t x, size_t y);

    WINDOW *win;

    size_t h, w;
    size_t y, x;

    friend class Ncurses;
};

class Ncurses {
public:
    using NcursesPtr = std::shared_ptr<Ncurses>;

    static NcursesPtr getInstance();

    NcursesWindow getWindow(size_t h, size_t w, size_t x, size_t y);

private:
    Ncurses();

    static NcursesPtr ncurses;
};

}