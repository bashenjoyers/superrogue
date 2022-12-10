#pragma once

#include <string>
#include <vector>
#include <optional>

struct Position {
  int x, y;
};

enum RenderEntityType {
  PERSON,
  ENEMY,
  ENEMY_COWARD,
  ENEMY_AGRESSIVE,
  ENEMY_FLYING,
  ENEMY_INDIFFERENT,
  ENEMY_ORDINARY,
  ENEMY_TRAVELER,
  ENEMY_REPLICATOR,
  WALL,
  SHADOW,
  FLOOR,
  ITEM,
  POTION,
  DOOR,
};

struct RenderOptions {
  int height;
  int width;
};

struct RenderEntity {
  Position pos;
  RenderEntityType type;
};

struct RenderItem {
  std::string name;
};

enum RenderEquipmentType {
  HELMET, ARMOR, BOOTS, WEAPON_MELEE, WEAPON_DISTANT
};

struct RenderInventoryInfo {
  std::vector<RenderItem> potions = {};
  std::optional<RenderItem> helmet = std::nullopt;
  std::optional<RenderItem> armor = std::nullopt;
  std::optional<RenderItem> boots = std::nullopt;
  std::optional<RenderItem> weapon_melee = std::nullopt;
  std::optional<RenderItem> weapon_distant = std::nullopt;
};

struct RenderPersonInfo {
  RenderInventoryInfo inventoryInfo;
  std::string name;
  std::string classDescription;
  bool isMelee;

  int armor;
  int damage;
  float luck;
  int dexterity;
  int health;
};

struct RenderUIData {
  size_t potionsCursor;
  RenderEquipmentType equipmentCursor;
};

struct RenderData {
  // options for map generation
  RenderOptions opts;
  // visible entities with their positions
  std::vector<RenderEntity> map_positions;
  // person info
  RenderPersonInfo personInfo;

  RenderUIData ui;
};