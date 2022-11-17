#pragma once

#include <memory>

#include "model/GameManager.h"
#include "controller/GameController.h"

#include "view/Renderer.h"
#include "view/Curses/CursesFactory.h"

class Boot {
public:
    Boot();

    void play();


private:
    std::shared_ptr<superrogue::game_manager::GameManager> gm;
    std::shared_ptr<superrogue::controller::GameController> gc;

    void firstFrameRender();

    float inventoryCoef = 0.3;
    superrogue::view::CursesFactory renderFactory;
};