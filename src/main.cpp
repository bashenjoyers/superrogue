#include "Boot.h"

int main() {
    Boot b;
    b.play();
    // auto gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions{.height = 30, .width = 60});
    // std::shared_ptr<GameModel::Map::Map> map = gm->generate_map();
    // map->step(GameModel::CharacterAction::WAIT);
}
