#include "ModelViewDataConverter.h"
#include "Model/UIModel/CursorState.h"

RenderData Controller::ModelViewDataConverter::convert(GameModel::Map::MapInfo mapInfo, UIModel::CursorState state) {
  return RenderData{
      .opts = convertOptions(mapInfo.mapOptions),
      .map_positions = convertMap(mapInfo.map_positions),
      .personInfo = convertPersonInfo(mapInfo),
      .ui = convertUIData(state),
  };
}

RenderOptions Controller::ModelViewDataConverter::convertOptions(GameModel::Map::MapOptions opts) {
  return RenderOptions{
      .height = opts.height,
      .width = opts.width,
  };
}

RenderPersonInfo Controller::ModelViewDataConverter::convertPersonInfo(GameModel::Map::MapInfo mapInfo) {
  return RenderPersonInfo{
      .inventoryInfo = convertInventoryInfo(mapInfo.inventory),
      .name = mapInfo.name,
      .classDescription = mapInfo.description,
      .isMelee = mapInfo.weapon_melee,

      .armor = mapInfo.characteristics.armor,
      .damage = mapInfo.characteristics.damage,
      .luck = mapInfo.characteristics.luck,
      .dexterity = mapInfo.characteristics.dexterity,
      .health = mapInfo.characteristics.health,
  };
}
RenderInventoryInfo Controller::ModelViewDataConverter::convertInventoryInfo(GameModel::Inventory::InventoryInfo info) {
  return RenderInventoryInfo{
      .potions = convertPotions(info.potions),
      .helmet = convertEquipmentItem(info.helmet),
      .armor = convertEquipmentItem(info.armor),
      .boots = convertEquipmentItem(info.boots),
      .weapon_melee = convertEquipmentItem(info.weapon_melee),
      .weapon_distant = convertEquipmentItem(info.weapon_distant),
  };
}

std::optional<RenderItem> Controller::ModelViewDataConverter::convertEquipmentItem(std::optional<GameModel::Item> item) {
  if (item.has_value()) {
    return RenderItem{
        .name = item.value().get_name()
    };
  } else {
    return std::nullopt;
  }
}

RenderItem Controller::ModelViewDataConverter::convertPotion(GameModel::Potion potion) {
  return RenderItem{
      .name = potion.get_name()
  };
}

std::vector<RenderItem> Controller::ModelViewDataConverter::convertPotions(const std::vector<GameModel::Potion> &potions) {
  std::vector<RenderItem> ans;
  for (GameModel::Potion p : potions) {
    ans.push_back(convertPotion(p));
  }

  return ans;
}

RenderUIData Controller::ModelViewDataConverter::convertUIData(UIModel::CursorState cursorState) {
  return RenderUIData{
      .potionsCursor = cursorState.getPotionsCursor(),
      .equipmentCursor = convertEquipmentType(cursorState.getEquipmentCursor()),
  };
}

RenderEquipmentType Controller::ModelViewDataConverter::convertEquipmentType(GameModel::ItemType type) {
  switch (type) {
  case GameModel::ItemType::HELMET: {
    return RenderEquipmentType::HELMET;
  }
  case GameModel::ItemType::ARMOR: {
    return RenderEquipmentType::ARMOR;
  }
  case GameModel::ItemType::BOOTS: {
    return RenderEquipmentType::BOOTS;
  }
  case GameModel::ItemType::WEAPON_MELEE: {
    return RenderEquipmentType::WEAPON_MELEE;
  }
  case GameModel::ItemType::WEAPON_DISTANT: {
    return RenderEquipmentType::WEAPON_DISTANT;
  }
  }
  return HELMET;
}
std::vector<RenderEntity> Controller::ModelViewDataConverter::convertMap(const std::vector<GameModel::Abstract::MapEntityWithPosition> &map) {
  std::vector<RenderEntity> entities;
  for (auto &mapEntity : map) {
    RenderEntityType t;
    switch (mapEntity.map_entity) {
    case GameModel::Abstract::MapEntity::PERSON:t = RenderEntityType::PERSON;
      break;
    case GameModel::Abstract::MapEntity::ENEMY:t = RenderEntityType::ENEMY;
      break;
    case GameModel::Abstract::MapEntity::ENEMY_COWARD:t = RenderEntityType::ENEMY_COWARD;
      break;
    case GameModel::Abstract::MapEntity::ENEMY_AGRESSIVE:t = RenderEntityType::ENEMY_AGRESSIVE;
      break;
    case GameModel::Abstract::MapEntity::ENEMY_FLYING:t = RenderEntityType::ENEMY_FLYING;
      break;
    case GameModel::Abstract::MapEntity::ENEMY_INDIFFERENT:t = RenderEntityType::ENEMY_INDIFFERENT;
      break;
    case GameModel::Abstract::MapEntity::ENEMY_ORDINARY:t = RenderEntityType::ENEMY_ORDINARY;
      break;
    case GameModel::Abstract::MapEntity::ENEMY_TRAVELER:t = RenderEntityType::ENEMY_TRAVELER;
      break;
    case GameModel::Abstract::MapEntity::ENEMY_REPLICATOR:t = RenderEntityType::ENEMY_REPLICATOR;
      break;
    case GameModel::Abstract::MapEntity::WALL:t = RenderEntityType::WALL;
      break;
    case GameModel::Abstract::MapEntity::SHADOW:t = RenderEntityType::SHADOW;
      break;
    case GameModel::Abstract::MapEntity::FLOOR:t = RenderEntityType::FLOOR;
      break;
    case GameModel::Abstract::MapEntity::ITEM:t = RenderEntityType::ITEM;
      break;
    case GameModel::Abstract::MapEntity::POTION:t = RenderEntityType::POTION;
      break;
    case GameModel::Abstract::MapEntity::DOOR:t = RenderEntityType::DOOR;
      break;
    }

    entities.push_back(RenderEntity{
        .pos = Position{
            .x = mapEntity.pos.x,
            .y = mapEntity.pos.y
        },
        .type = t,
    });
  }

  return entities;
}
