#pragma once

#include "Common/Observers.h"

#include "Model/GameModel/GameObject/Item/Stuff/Item.h"
#include "Model/GameModel/Map/Map.h"

namespace View {

struct RenderInfo {
  std::shared_ptr<GameModel::Map::MapInfo> mapInfo;
  std::shared_ptr<UIModel::CursorState> cursorState;
};

struct WindowConfig {
  size_t width;
  size_t height;
  size_t xPos;
  size_t yPos;
};

// TODO add I?
class Renderer {
public:
    ~Renderer() = default;
  virtual void render(RenderInfo info) = 0;

protected:
  WindowConfig config;
};

} // namespace View