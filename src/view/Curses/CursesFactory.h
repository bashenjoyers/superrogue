#pragma once

#include "CursesRenderer.h"

namespace superrogue::view {

struct TerminalInfo {
    size_t w, h;
};

class CursesFactory {
public:
    CursesFactory(float invMapCoef);

    void resync();

    std::shared_ptr<CursesMapRenderer> buildMapRenderer();
    std::shared_ptr<CursesMainMenuRenderer> buildMainMenuRenderer();
    std::shared_ptr<CursesInventoryRenderer> buildInventoryRenderer();
    

private:
    WindowConfig getMapWindowConfig();
    WindowConfig getInventoryWindowConfig();
    WindowConfig getMainMenuWindowConfig();

    std::shared_ptr<CursesMapRenderer> mapRenderer;
    std::shared_ptr<CursesMainMenuRenderer> mainMenuRenderer;
    std::shared_ptr<CursesInventoryRenderer> inventoryRenderer;

    TerminalInfo inf;
    float invMapCoef;
};

}