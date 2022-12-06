#include "Boot.h"

#include <memory>
#include <cassert>
using GameModel::Abstract::GameStatus;

// TODO
Boot::Boot() {}

void Boot::play() {
  gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions{.height = 30, .width = 40});
  renderer = std::make_shared<View::CursesRenderer>();
  std::shared_ptr<UIModel::CursorState> cursor = std::make_shared<UIModel::CursorState>();
  std::unique_ptr<Controller::EventProvider> provider = std::make_unique<Controller::EventProvider>(cursor, gm);
  provider->addObserver(renderer);

  gc = std::make_shared<Controller::GameController>(std::move(provider));

  while (true) {
	if (gm->isOver()) return;
	gc->interact();
  }
}

