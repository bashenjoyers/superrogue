#include "Boot.h"

#include <memory>

using superrogue::map::MapOptions;
using superrogue::map::Map;

using superrogue::game_manager::GameManager;
using superrogue::controller::GameController;

// TODO
Boot::Boot() : gm( std::make_shared<GameManager>(MapOptions {
    .height = 20,
    .width = 100
}) ), renderFactory(inventoryCoef) {}


void Boot::play() {
    std::shared_ptr<Map> map = gm->generate_map();
    gc = std::make_shared<GameController>(map);

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
    renderFactory.getInventoryRenderer()->handleEvent(0, superrogue::game_object::item::ItemType::HELMET);

    //renderFactory.getMapRenderer()->handleEvent(nullptr);
}

