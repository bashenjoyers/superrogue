#pragma once

#include "Model/GameModel/GameObject/Item/Stuff/Item.h"
#include "Model/GameModel/Map/Map.h"

#include <memory>


// TODO add I?
// TODO in Common???
class GameModelObserver {
public:
  virtual void
  handleEvent(std::shared_ptr<GameModel::Map::MapInfo> mapInfo) = 0;
};

class UIModelObserver {
public:
  virtual void handleEvent(size_t potionsCur,
                           GameModel::ItemType equipmentCur) = 0;
};
