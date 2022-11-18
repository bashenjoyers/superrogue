#include "Renderer.h"

namespace View {

void Renderer::handleEvent(std::shared_ptr<GameModel::Map::MapInfo> mapInfo) {
  RenderInfo info = {.mapInfo = mapInfo};
  render(info);
}

void Renderer::handleEvent(size_t potionsCur,
                           GameModel::ItemType equipmentCur) {
  RenderInfo info = {
      .mapInfo = nullptr,
      .potionsCursor = potionsCur,
      .equipmentCursor = equipmentCur,
  };
  render(info);
}

} // namespace View