#include "CursesRenderer.h"

namespace View {
    CursesRenderer::CursesRenderer() : Renderer() {
  resync();
  mainMenuRenderer = std::make_shared<CursesMainMenuRenderer>(getMainMenuWindowConfig());
        inventoryRenderer = std::make_shared<CursesInventoryRenderer>(getInventoryWindowConfig());
        mapRenderer = std::make_shared<CursesMapRenderer>(getMapWindowConfig());
        heroInfoRenderer = std::make_shared<CursesHeroInfoRenderer>(getHeroInfoWindowConfig());
}

void CursesRenderer::resync() {
  Ncurses::NcursesAPI::NcursesAPIPtr ncurses =
      Ncurses::NcursesAPI::getInstance();
    config = WindowConfig{.width = ncurses->getXsize(), .height = ncurses->getYsize(), .xPos = 0, .yPos = 0};

  if (mainMenuRenderer)
    mainMenuRenderer->resetWindow(getMainMenuWindowConfig());
  if (mapRenderer)
    mapRenderer->resetWindow(getMapWindowConfig());
  if (inventoryRenderer)
    inventoryRenderer->resetWindow(getInventoryWindowConfig());
}

WindowConfig CursesRenderer::getMapWindowConfig() {
  return WindowConfig{.width =
                          (size_t)((float)config.width * mapCoef),
                      .height = config.height,
                      .xPos = config.xPos + (size_t)((float)config.width * (1 - mapCoef)),
                      .yPos = config.yPos};
}

WindowConfig CursesRenderer::getInventoryWindowConfig() {
  return WindowConfig{.width = (size_t)((float)config.width * (1 - mapCoef)),
                      .height = (size_t)((float)config.height * (1 - heroInfoCoef)),
                      .xPos = config.xPos,
                      .yPos = config.yPos + (size_t)((float)config.height * heroInfoCoef)};
}

WindowConfig CursesRenderer::getMainMenuWindowConfig() {
  return config;
}

void CursesRenderer::handleEvent(std::shared_ptr<GameModel::Map::MapInfo> map,
                                std::shared_ptr<UIModel::CursorState> cursors) {
    RenderInfo info = {
            .mapInfo = map,
            .cursorState = cursors
    };
    render(info);
}

    void CursesRenderer::render(RenderInfo info) {
        mapRenderer->render(info);
        inventoryRenderer->render(info);
        heroInfoRenderer->render(info);
    }

    WindowConfig CursesRenderer::getHeroInfoWindowConfig() {
        return WindowConfig{.width = (size_t)((float)config.width * (1 - mapCoef)),
                .height = (size_t)((float)config.height * heroInfoCoef),
                .xPos = config.xPos,
                .yPos = config.yPos};
    }
} // namespace View