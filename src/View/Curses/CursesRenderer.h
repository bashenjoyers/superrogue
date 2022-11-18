#pragma once

#include "../Converters/CharDataConverter.h"
#include "../Renderer.h"

#include "Common/Ncurses/CursesAPI.h"

#include <optional>

namespace View {

// TODO howto handle resize

class CursesRenderer : public Renderer {
public:
  CursesRenderer(WindowConfig conf);
  virtual void resetWindow(WindowConfig newConf) override;

protected:
  CharConverter conv;
  Ncurses::NcursesWindow::NcursesWIndowPtr win;
};

class CursesMapRenderer : public CursesRenderer {
public:
  CursesMapRenderer(WindowConfig conf);

  virtual void render(RenderInfo info) override;
};

class CursesInventoryRenderer : public CursesRenderer {
public:
  CursesInventoryRenderer(WindowConfig conf);

  virtual void render(RenderInfo info) override;
  virtual void resetWindow(WindowConfig newConf) override;

private:
  void renderPotion(GameModel::Potion p, size_t row, bool selected);
  void renderItem(std::optional<GameModel::Item> item, GameModel::ItemType type,
                  bool selected);
  size_t getItemRowOffset(GameModel::ItemType type);

  Ncurses::NcursesWindow::NcursesWIndowPtr equipmentWin;
  Ncurses::NcursesWindow::NcursesWIndowPtr potionsWin;
};

class CursesMainMenuRenderer : public CursesRenderer {
public:
  CursesMainMenuRenderer(WindowConfig conf);

  virtual void render(RenderInfo info) override;
};

} // namespace View
