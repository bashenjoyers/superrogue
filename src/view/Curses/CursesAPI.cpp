#include "CursesAPI.h"

namespace Ncurses
{
NcursesWindow::~NcursesWindow() {
    wclear(win);
    wrefresh(win);
    delwin(win);
}


NcursesAPI::NcursesAPIPtr NcursesAPI::ncurses = nullptr;

void NcursesWindow::drawElement(char c, size_t x, size_t y) {
    mvwprintw(win, y, x, "%c", c);          // TODO handle frames
    wrefresh(win);
    refresh();
}

void NcursesWindow::resize(size_t w, size_t h) {
    werase(win);
    wrefresh(win);
    
    wresize(win, h, w);
    box(win, 0, 0);
    mvwprintw(win, 0, 1, "%s: %d x %d", "window", h, w); // TODO abstract
    wrefresh(win);
}

void NcursesWindow::moveTo(size_t x, size_t y) {
    werase(win);
    wrefresh(win);

    mvwin(win, y, x);
    box(win, 0, 0);
    mvwprintw(win, 0, 1, "%s: %d x %d", "window", h, w); // TODO abstract
    wrefresh(win);
}

NcursesWindow::NcursesWindow(WINDOW *_win, size_t h, size_t w, size_t x, size_t y) : win(_win), h(h), w(w), x(x), y(y) {}

NcursesAPI::~NcursesAPI() {
    endwin();
}

NcursesAPI::NcursesAPIPtr NcursesAPI::getInstance() {
    if (ncurses == nullptr) {
        ncurses = std::shared_ptr<NcursesAPI>(new NcursesAPI());
    }

    return ncurses;
}

NcursesWindow::NcursesWIndowPtr NcursesAPI::getWindow(size_t h, size_t w, size_t x, size_t y) {
    WINDOW *newWin = newwin(h, w, y, x);
    refresh();
    box(newWin, 0, 0);
    mvwprintw(newWin, 0, 1, "%s: %d x %d", "window", h, w);
    wrefresh(newWin);

    return std::shared_ptr<NcursesWindow>(new NcursesWindow(newWin, h, w, x, y));
}

NcursesAPI::NcursesAPI() {
    initscr();

}
}