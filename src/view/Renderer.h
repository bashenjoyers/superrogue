#pragma once

#include "ModelObserver.h"

namespace superrogue::view {

struct RenderInfo {
    std::shared_ptr<map::Map> map;
    std::shared_ptr<inventory::Inventory> inv;
};

struct WindowConfig {
    size_t width;
    size_t height;
    size_t xPos;
    size_t yPos;
};

// TODO add I?
class Renderer : public ModelObserver {
public:
    virtual void render(RenderInfo info) = 0;
    virtual void resetWindow(WindowConfig) = 0;

    void handleEvent(std::shared_ptr<map::Map> map, std::shared_ptr<inventory::Inventory> inv) override;

protected:
    WindowConfig conf;
};

}