#include "Renderer.h"


namespace superrogue::view {

void Renderer::handleEvent(std::shared_ptr<map::MapInfo> mapInfo) {
    RenderInfo info = {
        .mapInfo = mapInfo
    };
    render(info);
}

void Renderer::handleEvent(size_t potionsCur, game_object::item::ItemType equipmentCur) {
    RenderInfo info = {
        .mapInfo = nullptr,
        .potionsCursor = potionsCur,
        .equipmentCursor = equipmentCur,
    };
    render(info);
}

}