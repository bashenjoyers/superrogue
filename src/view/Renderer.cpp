#include "Renderer.h"


namespace superrogue::view {

void Renderer::handleEvent(std::shared_ptr<map::Map> map, std::shared_ptr<inventory::Inventory> inv) {
    RenderInfo info = {
        .map = map,
        .inv = inv
    };
    render(info);
}

}