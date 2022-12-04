#include "Boot.h"

#include <memory>
using GameModel::Abstract::GameStatus;

// TODO
Boot::Boot() {}

void Boot::play() {
    gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions{.height = 30, .width = 60});
    renderer = std::make_shared<View::CursesRenderer>();
    std::shared_ptr<GameModel::Map::World> map = gm->generate_map();
    std::shared_ptr<UIModel::CursorState> cursor =
            std::make_shared<UIModel::CursorState>();
    std::unique_ptr<Controller::EventProvider> provider =
            std::make_unique<Controller::EventProvider>(cursor, map);
    provider->addObserver(renderer);

    gc = std::make_shared<Controller::GameController>(std::move(provider));

    while (true) {
        if (map->get_game_status() == GameStatus::NEXT_LVL) {
            gm->generate_map();
        }

        if (map->get_game_status() == GameStatus::END) {
            return;
        }

        gc->interact();
    }
}

