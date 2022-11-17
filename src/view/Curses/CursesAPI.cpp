#include "CursesAPI.h"

#include <vector>
#include <iostream>

#define NOECHO_MODE 1

namespace Ncurses
{
NcursesWindow::~NcursesWindow() {
    wclear(win);
    wrefresh(win);
    delwin(win);
}


NcursesAPI::NcursesAPIPtr NcursesAPI::ncurses = nullptr;

void NcursesWindow::drawElement(char c, size_t x, size_t y, bool highlighted) {
    if (highlighted) wattron(win, A_STANDOUT);
    mvwaddch(win, bordersOffset + y, bordersOffset + x, c);          // TODO handle out of range
    if (highlighted) wattroff(win, A_STANDOUT);
    wrefresh(win);
    refresh();
}

void NcursesWindow::drawString(const std::string &s, size_t x, size_t y, bool highlighted) {
    if (highlighted) wattron(win, A_STANDOUT);
    mvwprintw(win, bordersOffset + y, bordersOffset + x, "%s", s.c_str());
    if (highlighted) wattroff(win, A_STANDOUT);
    wrefresh(win);
    refresh();
}

void NcursesWindow::resize(size_t newW, size_t newH) {
    w = newW;
    h = newH;
    clear();
    
    wresize(win, h, w);
    wrefresh(win);
    drawBox();
}

void NcursesWindow::moveTo(size_t newX, size_t newY) {
    x = newX;
    y = newY;
    clear();

    mvwin(win, y, x);
    wrefresh(win);
    drawBox();
}

void NcursesWindow::clear() {
    werase(win);
    wrefresh(win);
}

void NcursesWindow::clearViewport() {
    clear();
    drawBox();
}

void NcursesWindow::setName(const std::string &newName)
{
    name = newName;
    named = true;
}

void NcursesWindow::unsetName() {
    named = false;
}

NcursesWindow::NcursesWindow(WINDOW *_win, size_t h, size_t w, size_t x, size_t y) : win(_win), h(h), w(w), x(x), y(y) {}

void NcursesWindow::drawBox() {
    box(win, 0, 0);
    mvwprintw(win, 0, 1, "%s: %d x %d", "window", h, w);
    wrefresh(win);
}

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

size_t NcursesAPI::getXsize()
{
    return getmaxx(stdscr);
}

size_t NcursesAPI::getYsize()
{
    return getmaxy(stdscr);
}

NcursesAPI::NcursesAPI() {
    initscr();

    #if NOECHO_MODE
    noecho();
    #endif
}
}