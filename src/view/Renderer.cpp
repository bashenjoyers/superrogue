#include "Renderer.h"


namespace superrogue::view {

void Renderer::handleEvent(std::shared_ptr<map::Map> map, std::shared_ptr<inventory::Inventory> inv) {
    RenderInfo info = {
        .inv = inv,
        .map = map
    };
    render(info);
}

}