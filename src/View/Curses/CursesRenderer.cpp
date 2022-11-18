#include "CursesRenderer.h"
using namespace Ncurses;

namespace View {

CursesRenderer::CursesRenderer(WindowConfig conf) : Renderer() {
  NcursesAPI::NcursesAPIPtr ncurses = NcursesAPI::getInstance();
  win = ncurses->getWindow(conf.height, conf.width, conf.xPos, conf.yPos);
  win->setName("Viewport");
}

CursesMapRenderer::CursesMapRenderer(WindowConfig conf)
    : CursesRenderer(conf) {}

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
    : CursesRenderer(conf) {
  size_t eqTypeCnt = 5; // TODO
  NcursesAPI::NcursesAPIPtr ncurses = NcursesAPI::getInstance();
  equipmentWin = ncurses->getWindow(eqTypeCnt + 2, conf.width - 2,
                                    conf.xPos + 1, conf.yPos + 1);
  potionsWin =
      ncurses->getWindow(conf.height - eqTypeCnt - 2 - 2, conf.width - 2,
                         conf.xPos + 1, conf.yPos + 1 + eqTypeCnt + 2);
}

void CursesInventoryRenderer::render(RenderInfo info) {
  auto inventory = GameModel::Inventory::Inventory::getEmptyInventory();
  if (info.mapInfo != nullptr)
    inventory = info.mapInfo->inventory;

  auto potions = inventory.get_potions();
  size_t curRow = 0;

  for (auto potion : potions) {
    renderPotion(potion, curRow, curRow == info.potionsCursor);
    curRow++;
  }

  {
    using GameModel::ItemType;
    renderItem(inventory.get_armor(), ItemType::ARMOR,
               info.equipmentCursor == ItemType::ARMOR);
    renderItem(inventory.get_boots(), ItemType::BOOTS,
               info.equipmentCursor == ItemType::BOOTS);
    renderItem(inventory.get_helmet(), ItemType::HELMET,
               info.equipmentCursor == ItemType::HELMET);
    renderItem(inventory.get_weapon_distant(), ItemType::WEAPON_DISTANT,
               info.equipmentCursor == ItemType::WEAPON_DISTANT);
    renderItem(inventory.get_weapon_melee(), ItemType::WEAPON_MELEE,
               info.equipmentCursor == ItemType::WEAPON_MELEE);
  }
}

void CursesInventoryRenderer::resetWindow(WindowConfig newConf) {
  size_t eqTypeCnt = 5; // TODO
  CursesRenderer::resetWindow(newConf);

  equipmentWin->resize(eqTypeCnt + 2, conf.width - 2);
  equipmentWin->moveTo(conf.xPos + 1, conf.yPos + 1);
  potionsWin->resize(conf.height - eqTypeCnt - 2 - 2, conf.width - 2);
  potionsWin->moveTo(conf.xPos + 1, conf.yPos + 1 + eqTypeCnt + 2);
}

void CursesInventoryRenderer::renderPotion(GameModel::Potion p, size_t row,
                                           bool selected) {
  size_t padding = 1; // todo
  size_t symNamePadding = 3;

  char symbol = conv.convertPotion();
  potionsWin->drawElement(symbol, padding, row, selected);
  potionsWin->drawString(p.get_name(), padding + 1 + symNamePadding, row);
}

void CursesInventoryRenderer::renderItem(std::optional<GameModel::Item> item,
                                         GameModel::ItemType type,
                                         bool selected) {
  using GameModel::Item;

  char symbol = conv.convertItem(type);
  size_t padding = 1;
  size_t symNamePadding = 3;
  size_t row = getItemRowOffset(type);
  equipmentWin->drawElement(symbol, padding, row, selected);

  if (!item.has_value())
    return;

  Item i = item.value();
  equipmentWin->drawString(i.get_name(), padding + 1 + symNamePadding, row);
}

size_t CursesInventoryRenderer::getItemRowOffset(GameModel::ItemType type) {
  using GameModel::ItemType;

  switch (type) {
  case ItemType::ARMOR: {
    return 1;
  } break;

  case ItemType::BOOTS: {
    return 2;
  } break;

  case ItemType::HELMET: {
    return 0;
  } break;

  case ItemType::WEAPON_DISTANT: {
    return 4;
  } break;

  case ItemType::WEAPON_MELEE: {
    return 3;
  } break;

  default: {
    throw std::runtime_error("Unknown Item type"); // TODO
  } break;
  }
}

CursesMainMenuRenderer::CursesMainMenuRenderer(WindowConfig conf)
    : CursesRenderer(conf) {}

void CursesMainMenuRenderer::render(RenderInfo info) {}

void CursesRenderer::resetWindow(WindowConfig newConf) {
  conf = newConf;
  win->resize(conf.width, conf.height);
  win->moveTo(conf.xPos, conf.yPos);
}

} // namespace View