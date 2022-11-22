#pragma once

#include "Common/Observers.h"

#include "Model/GameModel/GameObject/Item/Stuff/Item.h"
#include "Model/GameModel/Map/Map.h"

namespace View {

/**
 * @brief Render sources, e.g. map definition, cursor positions
 * 
 */
struct RenderInfo {
  std::shared_ptr<GameModel::Map::MapInfo> mapInfo;
  std::shared_ptr<UIModel::CursorState> cursorState;
};

/**
 * @brief Window configuration for renderer.
 * 
 * @param width -- width of window
 * @param height -- height of window
 * @param xPos -- x position on screen (TOP LEFT ORIENTATION)
 * @param yPos -- y position on screen (TOP LEFT ORIENTATION)
 * 
 */
struct WindowConfig {
  size_t width;
  size_t height;
  size_t xPos;
  size_t yPos;
};

/**
 * @brief Interface of renderer. Can (surprisingly) render something based on model info
 * 
 */
class Renderer {
public:
    ~Renderer() = default;

  /**
   * @brief render info on screen
   * 
   * @param info -- current game/menu state to render
   */
  virtual void render(RenderInfo info) = 0;

protected:
  WindowConfig config;
};

} // namespace View