#include "Boot.h"

#include <memory>

// TODO
Boot::Boot()
    : gm(std::make_shared<GameModel::GameManager>(
          GameModel::Map::MapOptions{.height = 20, .width = 100})),
      renderFactory(inventoryCoef) {}

void Boot::play() {
  std::shared_ptr<GameModel::Map::Map> map = gm->generate_map();
  std::shared_ptr<UIModel::CursorState> cursor =
      std::make_shared<UIModel::CursorState>();
  std::unique_ptr<Controller::EventProvider> provider =
      std::make_unique<Controller::EventProvider>(cursor, map);

  gc = std::make_shared<Controller::GameController>(std::move(provider));

  gc->addModelObserver(renderFactory.getInventoryRenderer());
  gc->addModelObserver(renderFactory.getMapRenderer());

  gc->addUIObserver(renderFactory.getInventoryRenderer());

  firstFrameRender();

  while (true) {
    gc->interact();
  }
}

void Boot::firstFrameRender() {
  renderFactory.getInventoryRenderer()->handleEvent(nullptr);
  renderFactory.getInventoryRenderer()->handleEvent(
      0, GameModel::ItemType::HELMET);

  // renderFactory.getMapRenderer()->handleEvent(nullptr);
}
