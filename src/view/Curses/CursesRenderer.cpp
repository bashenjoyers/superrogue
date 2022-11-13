#include "CursesRenderer.h"
using namespace Ncurses;

namespace superrogue::view {

CursesRenderer::CursesRenderer(WindowConfig conf) : Renderer() {
    NcursesAPI::NcursesAPIPtr ncurses = NcursesAPI::getInstance();
    win = ncurses->getWindow(conf.height, conf.width, conf.xPos, conf.yPos);
    win->setName("Viewport");
}

CursesMapRenderer::CursesMapRenderer(WindowConfig conf) : CursesRenderer(conf) {}

void CursesMapRenderer::render(RenderInfo info) {
    win->clearViewport();
    std::vector<std::vector<char>> renderMap = conv.convertMap(info.map);

    for (size_t y = 0; y < renderMap[0].size(); y++) {
        for (size_t x = 0; x < renderMap.size(); x++) {
            win->drawElement(renderMap[x][y], x, y);
        }
    }
}

CursesInventoryRenderer::CursesInventoryRenderer(WindowConfig conf) : CursesRenderer(conf) {
    size_t eqTypeCnt = 5;           // TODO
    NcursesAPI::NcursesAPIPtr ncurses = NcursesAPI::getInstance();
    equipmentWin = ncurses->getWindow(eqTypeCnt + 2, conf.width - 2, conf.xPos + 1, conf.yPos + 1);
    potionsWin = ncurses->getWindow(conf.height - eqTypeCnt - 2 - 2, conf.width - 2, conf.xPos + 1, conf.yPos + 1 + eqTypeCnt + 2);
}

void CursesInventoryRenderer::render(RenderInfo info) {
    auto inventory = info.inv;
    if (inventory == nullptr) return;

    auto potions = inventory->get_potions();
    size_t curRow = 0;
    size_t padding = 1;
    size_t symNamePadding = 3;
    for (auto potion: potions) {
        char symbol = conv.convertPotion();
        potionsWin->drawElement(symbol, padding, curRow);
        potionsWin->drawString(potion.get_name(), padding + 1 + symNamePadding, curRow);
        curRow++;
    }

    {
        renderItem(inventory->get_armor());
        renderItem(inventory->get_boots());
        renderItem(inventory->get_helmet());
        renderItem(inventory->get_weapon_distant());
        renderItem(inventory->get_weapon_melee());
    }
}

void CursesInventoryRenderer::resetWindow(WindowConfig newConf) {
    size_t eqTypeCnt = 5;           // TODO
    CursesRenderer::resetWindow(newConf);

    equipmentWin->resize(eqTypeCnt + 2, conf.width - 2);
    equipmentWin->moveTo(conf.xPos + 1, conf.yPos + 1);
    potionsWin->resize(conf.height - eqTypeCnt - 2 - 2, conf.width - 2);
    potionsWin->moveTo(conf.xPos + 1, conf.yPos + 1 + eqTypeCnt + 2);
}

void CursesInventoryRenderer::renderItem(std::optional<superrogue::game_object::item::Item> item) {
    using superrogue::game_object::item::Item;
    if (!item.has_value()) return;

    Item i = item.value();
    size_t row = getItemRowOffset(i);                //todo pass only type
    char symbol = conv.convertItem(i.get_item_type());

    size_t padding = 1;
    size_t symNamePadding = 3;

    equipmentWin->drawElement(symbol, padding, row);
    equipmentWin->drawString(i.get_name(), padding + 1 + symNamePadding, row);
}

size_t CursesInventoryRenderer::getItemRowOffset(const superrogue::game_object::item::Item &item) {
    using superrogue::game_object::item::ItemType;

    switch (item.get_item_type()) {
        case ItemType::ARMOR : {
            return 0;
        } break;

        case ItemType::BOOTS : {
            return 1;
        } break;

        case ItemType::HELMET : {
            return 2;
        } break;

        case ItemType::WEAPON_DISTANT : {
            return 3;
        } break;

        case ItemType::WEAPON_MELEE : {
            return 4;
        } break;

        default : {
            throw std::runtime_error("Unknown item type");  // TODO
        } break;
    }
}

CursesMainMenuRenderer::CursesMainMenuRenderer(WindowConfig conf) : CursesRenderer(conf) {}

void CursesMainMenuRenderer::render(RenderInfo info)
{
    
}

void CursesRenderer::resetWindow(WindowConfig newConf) {
    conf = newConf;
    win->resize(conf.width, conf.height);
    win->moveTo(conf.xPos, conf.yPos);
}

}