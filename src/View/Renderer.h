#pragma once

#include "Observers.h"

namespace View {

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
  virtual void render(RenderData data) = 0;

protected:
  WindowConfig config;
};

} // namespace View