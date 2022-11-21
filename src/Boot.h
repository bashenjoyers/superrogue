#pragma once

#include <memory>

#include "Controller/GameController.h"
#include "Model/GameModel/GameManager.h"

#include "View/Curses/CursesRenderer.h"
#include "View/Renderer.h"

class Boot {
public:
  Boot();

  void play();

private:
  std::shared_ptr<GameModel::GameManager> gm;
  std::shared_ptr<Controller::GameController> gc;

    std::shared_ptr<View::CursesRenderer> renderer;

    GameModel::Map::MapOptions mapOptions = {
            .height = 30,
            .width = 60,
    };

};