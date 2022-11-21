#pragma once

#include "Model/GameModel/GameObject/Item/Stuff/Item.h"
#include "Model/GameModel/Map/Map.h"
#include "Model/UIModel/CursorState.h"

#include <memory>


// TODO add I?
// TODO in Common???
class ModelObserver {
public:
  virtual void
  handleEvent(std::shared_ptr<GameModel::Map::MapInfo> mapInfo, std::shared_ptr<UIModel::CursorState> cursors) = 0;
};

