#pragma once

#include "CursesSubRenderer.h"

namespace View {

/**
 * @brief Curses main renderer class. Observing model events
 * 
 */
class CursesRenderer : public Renderer, public RenderDataObserver {
public:
    CursesRenderer();

  /**
   * @brief resync with current terminal size
   * 
   */
  void resync();

  /**
   * @brief render all the game state
   * 
   * @param info -- current game state
   */
    void render(RenderData data) override;

    /**
     * @brief handle model event
     * 
     * @param map -- current map state
     * @param cursors -- current cursors positions
     */
    void handleEvent(RenderData data) override;

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