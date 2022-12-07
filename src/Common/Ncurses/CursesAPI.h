#pragma once

#include <memory>
#include <ncurses.h>
#include <string>

namespace Ncurses {

class Ncurses;

class NcursesWindow {
public:
  using NcursesWIndowPtr = std::shared_ptr<NcursesWindow>;
  ~NcursesWindow();

  void drawElement(char c, size_t x, size_t y, bool highlighted = false);
  void drawString(const std::string &s, size_t x, size_t y,
                  bool highlighted = false);

  void resize(size_t newW, size_t newH);
  void moveTo(size_t newX, size_t newY);

  void clear();
  void clearViewport();

  void setName(const std::string &newName);
  void unsetName();

private:
  NcursesWindow(WINDOW *_win, size_t h, size_t w, size_t x, size_t y);

  void drawBox();

  WINDOW *win;

  size_t h, w;
  size_t y, x;

  bool named = false;
  std::string name;

  size_t bordersOffset = 1;

  friend class NcursesAPI;
};

class NcursesAPI {
public:
  using NcursesAPIPtr = std::shared_ptr<NcursesAPI>;
  ~NcursesAPI();

  static NcursesAPIPtr getInstance();

  NcursesWindow::NcursesWIndowPtr getWindow(size_t h, size_t w, size_t x,
                                            size_t y);
  size_t getXsize();
  size_t getYsize();

  int getKey();

private:
  NcursesAPI();

  static NcursesAPIPtr ncurses;
};

} // namespace Ncurses