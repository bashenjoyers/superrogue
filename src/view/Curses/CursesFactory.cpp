#include "CursesFactory.h"


namespace superrogue::view
{
    CursesFactory::CursesFactory(float invMapCoef) : invMapCoef(invMapCoef) {
        resync();
    }
    
    void CursesFactory::resync() {
        Ncurses::NcursesAPI::NcursesAPIPtr ncurses = Ncurses::NcursesAPI::getInstance();
        inf = TerminalInfo {
            .h = ncurses->getYsize(),
            .w = ncurses->getXsize()
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
        
    }
    
    WindowConfig CursesFactory::getMapWindowConfig()
    {
        return WindowConfig {
            .height = inf.h,
            .width = (size_t) ((float) inf.w - (float) inf.w * invMapCoef),
            .xPos = (size_t) ((float) inf.w * invMapCoef),
            .yPos = 0
        };
    }
    
    WindowConfig CursesFactory::getInventoryWindowConfig()
    {
        return WindowConfig {
            .height = inf.h,
            .width = (size_t) ((float) inf.w * invMapCoef),
            .xPos = 0,
            .yPos = 0
        };
    }
    
    WindowConfig CursesFactory::getMainMenuWindowConfig()
    {
        return WindowConfig {
            .height = inf.h,
            .width = inf.w,
            .xPos = 0,
            .yPos = 0
        };
    }
}