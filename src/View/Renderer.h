#pragma once

#include "Common/Observers.h"

#include "Model/GameModel/GameObject/Item/Stuff/Item.h"
#include "Model/GameModel/Map/Map.h"

namespace View {

struct RenderInfo {
  std::shared_ptr<GameModel::Map::MapInfo> mapInfo;
  size_t potionsCursor = 0;
  GameModel::ItemType equipmentCursor = GameModel::ItemType::ARMOR;
};

struct WindowConfig {
  size_t width;
  size_t height;
  size_t xPos;
  size_t yPos;
};

// TODO add I?
class Renderer : public GameModelObserver, public UIModelObserver {
public:
  virtual void render(RenderInfo info) = 0;

  virtual void resetWindow(WindowConfig) = 0;

  void handleEvent(std::shared_ptr<GameModel::Map::MapInfo> map) override;

  void handleEvent(size_t potionsCur,
                   GameModel::ItemType equipmentCur) override;

protected:
  WindowConfig conf;
};

} // namespace View