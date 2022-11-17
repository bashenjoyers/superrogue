#include "Renderer.h"


namespace superrogue::view {

void Renderer::handleEvent(std::shared_ptr<map::MapInfo> mapInfo) {
    RenderInfo info = {
        .mapInfo = mapInfo
    };
    render(info);
}

}