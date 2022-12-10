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

void CursesMapRenderer::render(RenderData data) {
  win->clearViewport();
  std::vector<std::vector<char>> renderMap = conv.convertMap(data.map_positions, data.opts);

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

void CursesInventoryRenderer::render(RenderData data) {
  potionsWin->clearViewport();
  equipmentWin->clearViewport();

  auto potions = data.personInfo.inventoryInfo.potions;

  for (size_t curRow = 0; curRow < maxPotions; curRow++) {
	if (curRow < potions.size())
	  renderPotion(potions[curRow], curRow, curRow == data.ui.potionsCursor);
	else
	  renderEmptyPotion(curRow, curRow == data.ui.potionsCursor);
  }

  {
	renderItem(data.personInfo.inventoryInfo.armor, RenderEquipmentType::ARMOR,
			   data.ui.equipmentCursor == RenderEquipmentType::ARMOR);
	renderItem(data.personInfo.inventoryInfo.boots, RenderEquipmentType::BOOTS,
               data.ui.equipmentCursor == RenderEquipmentType::BOOTS);
	renderItem(data.personInfo.inventoryInfo.helmet, RenderEquipmentType::HELMET,
               data.ui.equipmentCursor == RenderEquipmentType::HELMET);
	renderItem(data.personInfo.inventoryInfo.weapon_distant, RenderEquipmentType::WEAPON_DISTANT,
               data.ui.equipmentCursor == RenderEquipmentType::WEAPON_DISTANT);
	renderItem(data.personInfo.inventoryInfo.weapon_melee, RenderEquipmentType::WEAPON_MELEE,
               data.ui.equipmentCursor == RenderEquipmentType::WEAPON_MELEE);
  }
}

void CursesInventoryRenderer::resetWindow(WindowConfig newConf) {
  CursesSubRenderer::resetWindow(newConf);

  spawnEquipmentWindow();
  spawnPotionsWindow();
}

void CursesInventoryRenderer::renderPotion(RenderItem p, size_t row,
										   bool selected) {
  size_t symbolPadding = 1;
  size_t namePadding = symbolPadding + 3;

  char symbol = conv.convertPotion();
  potionsWin->drawElement(symbol, symbolPadding, row, selected);
  potionsWin->drawString(p.name, namePadding, row);
}

void CursesInventoryRenderer::renderItem(std::optional<RenderItem> item,
										 RenderEquipmentType type,
										 bool selected) {
  size_t symbolPadding = 1;
  size_t namePadding = symbolPadding + 3;

  char symbol = conv.convertItem(type);

  size_t row = typeToPos(type);
  equipmentWin->drawElement(symbol, symbolPadding, row, selected);

  if (!item.has_value())
	return;

  equipmentWin->drawString(item.value().name, namePadding, row);
}

size_t CursesInventoryRenderer::typeToPos(RenderEquipmentType type) {

  switch (type) {
  case RenderEquipmentType::ARMOR: {
	return 1;
  }
	break;

  case RenderEquipmentType::BOOTS: {
	return 2;
  }
	break;

  case RenderEquipmentType::HELMET: {
	return 0;
  }
	break;

  case RenderEquipmentType::WEAPON_DISTANT: {
	return 4;
  }
	break;

  case RenderEquipmentType::WEAPON_MELEE: {
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

void CursesMainMenuRenderer::render(RenderData data) {}

void CursesSubRenderer::resetWindow(WindowConfig newConf) {
  config = newConf;
  win->resize(config.width, config.height);
  win->moveTo(config.xPos, config.yPos);
}

void CursesHeroInfoRenderer::render(RenderData data) {
  characteristicsWin->clearViewport();
  renderCharacteristics(data.personInfo);
}

CursesHeroInfoRenderer::CursesHeroInfoRenderer(WindowConfig conf) : CursesSubRenderer(conf) {
  win->setName("Hero Info");
  spawnCharacteristicsWindow();
}

void CursesHeroInfoRenderer::renderCharacteristics(RenderPersonInfo personInfo) {
  characteristicsWin->drawString("ARMOR: " + std::to_string(personInfo.armor), 0, 0, false);
  characteristicsWin->drawString("DAMAGE: " + std::to_string(personInfo.damage), 0, 1, false);
  characteristicsWin->drawString("DEXTERITY: " + std::to_string(personInfo.dexterity), 0, 2, false);
  characteristicsWin->drawString("HEALTH: " + std::to_string(personInfo.health), 0, 3, false);
  characteristicsWin->drawString("LUCK: " + std::to_string(personInfo.luck), 0, 4, false);
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