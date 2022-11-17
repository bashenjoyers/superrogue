#include "CursesFactory.h"


namespace superrogue::view
{
    CursesFactory::CursesFactory(float invMapCoef) : invMapCoef(invMapCoef) {
        resync();
    }
    
    void CursesFactory::resync() {
        Ncurses::NcursesAPI::NcursesAPIPtr ncurses = Ncurses::NcursesAPI::getInstance();
        inf = TerminalInfo {
            .w = ncurses->getXsize(),
            .h = ncurses->getYsize()
        };

        if (mainMenuRenderer)
            mainMenuRenderer->resetWindow(getMainMenuWindowConfig());
        if (mapRenderer)
            mapRenderer->resetWindow(getMapWindowConfig());
        if (inventoryRenderer)
            inventoryRenderer->resetWindow(getInventoryWindowConfig());
    }
    
    std::shared_ptr<CursesMapRenderer> CursesFactory::buildMapRenderer()
    {
        mapRenderer = std::make_shared<CursesMapRenderer>(getMapWindowConfig());
        return mapRenderer;
    }
    
    std::shared_ptr<CursesMainMenuRenderer> CursesFactory::buildMainMenuRenderer() {
        
    }
    
    std::shared_ptr<CursesInventoryRenderer> CursesFactory::buildInventoryRenderer()
    {
        inventoryRenderer = std::make_shared<CursesInventoryRenderer>(getInventoryWindowConfig());
        return inventoryRenderer;
    }
    
    WindowConfig CursesFactory::getMapWindowConfig()
    {
        return WindowConfig {
            .width = (size_t) ((float) inf.w - (float) inf.w * invMapCoef),
            .height = inf.h,
            .xPos = (size_t) ((float) inf.w * invMapCoef),
            .yPos = 0
        };
    }
    
    WindowConfig CursesFactory::getInventoryWindowConfig()
    {
        return WindowConfig {
            .width = (size_t) ((float) inf.w * invMapCoef),
            .height = inf.h,
            .xPos = 0,
            .yPos = 0
        };
    }
    
    WindowConfig CursesFactory::getMainMenuWindowConfig()
    {
        return WindowConfig {
            .width = inf.w,
            .height = inf.h,
            .xPos = 0,
            .yPos = 0
        };
    }
}