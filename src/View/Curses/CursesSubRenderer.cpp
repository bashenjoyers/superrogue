#include "CursesSubRenderer.h"
using namespace Ncurses;

namespace View {

CursesSubRenderer::CursesSubRenderer(WindowConfig conf) {
  config = conf;
  NcursesAPI::NcursesAPIPtr ncurses = NcursesAPI::getInstance();
  win = ncurses->getWindow(conf.height, conf.width, conf.xPos, conf.yPos);
}

CursesMapRenderer::CursesMapRenderer(WindowConfig conf)
	: CursesSubRenderer(conf) {
  win->setName("Map");
}

void CursesMapRenderer::render(RenderInfo info) {
  win->clearViewport();
  std::vector<std::vector<char>> renderMap = conv.convertMap(info.mapInfo);

  for (size_t y = 0; y < renderMap[0].size(); y++) {
	for (size_t x = 0; x < renderMap.size(); x++) {
	  win->drawElement(renderMap[x][y], x, y);
	}
  }
}

CursesInventoryRenderer::CursesInventoryRenderer(WindowConfig conf)
	: CursesSubRenderer(conf) {
  win->setName("Inventory");
  spawnEquipmentWindow();
  spawnPotionsWindow();
}

void CursesInventoryRenderer::render(RenderInfo info) {
  potionsWin->clearViewport();
  equipmentWin->clearViewport();
  GameModel::Inventory::InventoryInfo inventory;
  if (info.mapInfo != nullptr)
	inventory = info.mapInfo->inventory;

  auto potions = inventory.potions;

  for (size_t curRow = 0; curRow < maxPotions; curRow++) {
	if (curRow < potions.size())
	  renderPotion(potions[curRow], curRow, curRow == info.cursorState->getPotionsCursor());
	else
	  renderEmptyPotion(curRow, curRow == info.cursorState->getPotionsCursor());
  }

  {
	using GameModel::ItemType;
	renderItem(inventory.armor, ItemType::ARMOR,
			   info.cursorState->getEquipmentCursor() == ItemType::ARMOR);
	renderItem(inventory.boots, ItemType::BOOTS,
			   info.cursorState->getEquipmentCursor() == ItemType::BOOTS);
	renderItem(inventory.helmet, ItemType::HELMET,
			   info.cursorState->getEquipmentCursor() == ItemType::HELMET);
	renderItem(inventory.weapon_distant, ItemType::WEAPON_DISTANT,
			   info.cursorState->getEquipmentCursor() == ItemType::WEAPON_DISTANT);
	renderItem(inventory.weapon_melee, ItemType::WEAPON_MELEE,
			   info.cursorState->getEquipmentCursor() == ItemType::WEAPON_MELEE);
  }
}

void CursesInventoryRenderer::resetWindow(WindowConfig newConf) {
  CursesSubRenderer::resetWindow(newConf);

  spawnEquipmentWindow();
  spawnPotionsWindow();
}

void CursesInventoryRenderer::renderPotion(GameModel::Potion p, size_t row,
										   bool selected) {
  size_t symbolPadding = 1;
  size_t namePadding = symbolPadding + 3;

  char symbol = conv.convertPotion();
  potionsWin->drawElement(symbol, symbolPadding, row, selected);
  potionsWin->drawString(p.get_name(), namePadding, row);
}

void CursesInventoryRenderer::renderItem(std::optional<GameModel::Item> item,
										 GameModel::ItemType type,
										 bool selected) {
  using GameModel::Item;
  size_t symbolPadding = 1;
  size_t namePadding = symbolPadding + 3;

  char symbol = conv.convertItem(type);

  size_t row = getItemRowOffset(type);
  equipmentWin->drawElement(symbol, symbolPadding, row, selected);

  if (!item.has_value())
	return;

  Item i = item.value();
  equipmentWin->drawString(i.get_name(), namePadding, row);
}

size_t CursesInventoryRenderer::getItemRowOffset(GameModel::ItemType type) {
  using GameModel::ItemType;

  switch (type) {
  case ItemType::ARMOR: {
	return 1;
  }
	break;

  case ItemType::BOOTS: {
	return 2;
  }
	break;

  case ItemType::HELMET: {
	return 0;
  }
	break;

  case ItemType::WEAPON_DISTANT: {
	return 4;
  }
	break;

  case ItemType::WEAPON_MELEE: {
	return 3;
  }
	break;

  default: {
	throw std::runtime_error("Unknown Item type"); // TODO
  }
	break;
  }
}

void CursesInventoryRenderer::spawnEquipmentWindow() {
  NcursesAPI::NcursesAPIPtr ncurses = NcursesAPI::getInstance();
  size_t bordersCount = 2;
  size_t rowsCount = maxEquipment + bordersCount;

  size_t subWindowSizeX = config.width - bordersCount;
  size_t subWindowOffset = 1;
  equipmentWin = ncurses->getWindow(rowsCount, subWindowSizeX,
									config.xPos + subWindowOffset, config.yPos + subWindowOffset);
  equipmentWin->setName("Equipment");
}

void CursesInventoryRenderer::spawnPotionsWindow() {
  NcursesAPI::NcursesAPIPtr ncurses = NcursesAPI::getInstance();
  size_t bordersCount = 2;
  size_t rowsCount = maxPotions + bordersCount;

  size_t subWindowSizeX = config.width - bordersCount;
  size_t subWindowOffsetX = 1;
  size_t subWindowOffsetY = maxEquipment + bordersCount + 1;

  potionsWin =
	  ncurses->getWindow(rowsCount, subWindowSizeX,
						 config.xPos + subWindowOffsetX, config.yPos + subWindowOffsetY);
  potionsWin->setName("Potions");
}

void CursesInventoryRenderer::renderEmptyPotion(size_t row, bool selected) {
  size_t symbolPadding = 1;

  char symbol = conv.convertPotion();
  potionsWin->drawElement(symbol, symbolPadding, row, selected);
}

CursesMainMenuRenderer::CursesMainMenuRenderer(WindowConfig conf)
	: CursesSubRenderer(conf) {}

void CursesMainMenuRenderer::render(RenderInfo info) {}

void CursesSubRenderer::resetWindow(WindowConfig newConf) {
  config = newConf;
  win->resize(config.width, config.height);
  win->moveTo(config.xPos, config.yPos);
}

void CursesHeroInfoRenderer::render(RenderInfo info) {
  characteristicsWin->clearViewport();
  renderCharacteristics(info.mapInfo->characteristics);
}

CursesHeroInfoRenderer::CursesHeroInfoRenderer(WindowConfig conf) : CursesSubRenderer(conf) {
  win->setName("Hero Info");
  spawnCharacteristicsWindow();
}

void CursesHeroInfoRenderer::renderCharacteristics(GameModel::Characteristics characteristics) {
  characteristicsWin->drawString("ARMOR: " + std::to_string(characteristics.armor), 0, 0, false);
  characteristicsWin->drawString("DAMAGE: " + std::to_string(characteristics.damage), 0, 1, false);
  characteristicsWin->drawString("DEXTERITY: " + std::to_string(characteristics.dexterity), 0, 2, false);
  characteristicsWin->drawString("HEALTH: " + std::to_string(characteristics.health), 0, 3, false);
  characteristicsWin->drawString("LUCK: " + std::to_string(characteristics.luck), 0, 4, false);
}

void CursesHeroInfoRenderer::spawnCharacteristicsWindow() {
  NcursesAPI::NcursesAPIPtr ncurses = NcursesAPI::getInstance();
  size_t bordersCount = 2;
  size_t rowsCount = characteristicsCount + bordersCount;

  size_t subWindowSizeX = config.width - bordersCount;
  size_t subWindowOffset = 1;
  characteristicsWin = ncurses->getWindow(rowsCount, subWindowSizeX,
										  config.xPos + subWindowOffset, config.yPos + subWindowOffset);
  characteristicsWin->setName("Characteristics");
}

void CursesHeroInfoRenderer::resetWindow(WindowConfig newConf) {
  CursesSubRenderer::resetWindow(newConf);

  spawnCharacteristicsWindow();
}
} // namespace View