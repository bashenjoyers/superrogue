#include "Boot.h"

#include <memory>
#include <cassert>
using GameModel::Abstract::GameStatus;

// TODO
Boot::Boot() {}

void debug(GameModel::Map::MapInfo info) {
  View::CharConverter conv;
  auto p = conv.convertMap(std::make_shared<GameModel::Map::MapInfo>(info));

  for (size_t i = 0; i < p.size(); i++) {
	for (size_t j = 0; j < p[0].size(); j++) {
	  std::cout << p[i][j];
	}
	std::cout << '\n';
  }
  std::cout << '\n';std::cout << '\n';std::cout << '\n';
}

void Boot::play() {
  gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions{.height = 10, .width = 10});
  renderer = std::make_shared<View::CursesRenderer>();
  std::shared_ptr<UIModel::CursorState> cursor = std::make_shared<UIModel::CursorState>();
  std::unique_ptr<Controller::EventProvider> provider = std::make_unique<Controller::EventProvider>(cursor, gm);
  provider->addObserver(renderer);

  gc = std::make_shared<Controller::GameController>(std::move(provider));

  while (true) {
	if (gm->isOver()) assert(false);
	gc->interact();
  }
}

