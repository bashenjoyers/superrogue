#pragma once

#include "CursesSubRenderer.h"

namespace View {

class CursesRenderer : public Renderer, public ModelObserver {
public:
    CursesRenderer();

  void resync();

    void render(RenderInfo info) override;
    void handleEvent(std::shared_ptr<GameModel::Map::MapInfo> map, std::shared_ptr<UIModel::CursorState> cursors) override;

private:
  WindowConfig getMapWindowConfig();
  WindowConfig getInventoryWindowConfig();
  WindowConfig getMainMenuWindowConfig();
    WindowConfig getHeroInfoWindowConfig();

  std::shared_ptr<CursesMapRenderer> mapRenderer;
  std::shared_ptr<CursesMainMenuRenderer> mainMenuRenderer;
  std::shared_ptr<CursesInventoryRenderer> inventoryRenderer;
  std::shared_ptr<CursesHeroInfoRenderer> heroInfoRenderer;

  float mapCoef = 0.7;
  float heroInfoCoef = 0.5;
  size_t heroInfoWindowSize = 5 + 2 + 2; // chars + borders + borders TODO
};

} // namespace View