#pragma once

#include <ncurses.h>
#include <memory>

namespace Ncurses {

class Ncurses;

class NcursesWindow {
public:
    using NcursesWIndowPtr = std::shared_ptr<NcursesWindow>;
    ~NcursesWindow();

    void drawElement(char c, size_t x, size_t y);

    void resize(size_t w, size_t h);
    void moveTo(size_t x, size_t y);

private:
    NcursesWindow(WINDOW *_win, size_t h, size_t w, size_t x, size_t y);

    WINDOW *win;

    size_t h, w;
    size_t y, x;

    friend class NcursesAPI;
};

class NcursesAPI {
public:
    using NcursesAPIPtr = std::shared_ptr<NcursesAPI>;
    ~NcursesAPI();


    static NcursesAPIPtr getInstance();

    NcursesWindow::NcursesWIndowPtr getWindow(size_t h, size_t w, size_t x, size_t y);

private:
    NcursesAPI();

    static NcursesAPIPtr ncurses;
};

}