#pragma once

#include <memory>

#include "Model/GameModel/GameManager.h"
#include "Controller/GameController.h"

#include "View/Renderer.h"
#include "View/Curses/CursesFactory.h"

class Boot {
public:
    Boot();

    void play();


private:
    std::shared_ptr<GameModel::GameManager> gm;
    std::shared_ptr<Controller::GameController> gc;

    void firstFrameRender();

    float inventoryCoef = 0.3;
    View::CursesFactory renderFactory;
};