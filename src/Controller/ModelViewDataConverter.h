#pragma once

#include "View/RenderData.h"
#include "Model/GameModel/Map/World.h"
#include "Model/GameModel/Inventory/Inventory.h"
#include "Model/UIModel/CursorState.h"

namespace Controller {

class ModelViewDataConverter {
public:
  RenderData convert(GameModel::Map::MapInfo mapInfo, UIModel::CursorState state);
private:
  RenderOptions convertOptions(GameModel::Map::MapOptions opts);
  RenderPersonInfo convertPersonInfo(GameModel::Map::MapInfo mapInfo);
  RenderInventoryInfo convertInventoryInfo(GameModel::Inventory::InventoryInfo info);
  std::optional<RenderItem> convertEquipmentItem(std::optional<GameModel::Item> item);
  RenderItem convertPotion(GameModel::Potion potion);
  std::vector<RenderItem> convertPotions(const std::vector<GameModel::Potion> &potions);
  RenderUIData convertUIData(UIModel::CursorState cursorState);
  RenderEquipmentType convertEquipmentType(GameModel::ItemType type);
  std::vector<RenderEntity> convertMap(const std::vector<GameModel::Abstract::MapEntityWithPosition> &map);
};

}
