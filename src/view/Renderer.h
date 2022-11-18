#pragma once

#include "common/Observers.h"
#include "model/game_object/item/stuff/Item.h"

namespace superrogue::view {

struct RenderInfo {
    std::shared_ptr<map::MapInfo> mapInfo;
    size_t potionsCursor = 0;
    game_object::item::ItemType equipmentCursor = game_object::item::ItemType::ARMOR;
};

struct WindowConfig {
    size_t width;
    size_t height;
    size_t xPos;
    size_t yPos;
};

// TODO add I?
class Renderer : public ModelObserver, public UIObserver {
public:
    virtual void render(RenderInfo info) = 0;
    virtual void resetWindow(WindowConfig) = 0;

    void handleEvent(std::shared_ptr<map::MapInfo> map) override;
    void handleEvent(size_t potionsCur, game_object::item::ItemType equipmentCur) override;

protected:
    WindowConfig conf;
};

}