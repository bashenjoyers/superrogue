#include <gtest/gtest.h>
#include "Model/GameModel/Map/Map.h"
#include "Model/UIModel/Events/MovePotionDownEvent.h"

TEST(MOVE_POTION_DOWN_EVENT_TESTS, TEST_EXECUTE) {
    std::set<GameModel::Enemy> enemies = std::set<GameModel::Enemy>();
    std::shared_ptr<GameModel::Person> person = std::make_shared<GameModel::Person>();
    GameModel::Map::MapOptions mapOptions = GameModel::Map::MapOptions();
    mapOptions.height = 24;
    mapOptions.width = 24;
    std::shared_ptr<GameModel::Map::Map> map = std::make_shared<GameModel::Map::Map>(enemies, person, mapOptions, 0);

    std::shared_ptr<UIModel::CursorState> cursorState = std::make_shared<UIModel::CursorState>();
    GameModel::Events::MovePotionDownEvent movePotionDownEvent = GameModel::Events::MovePotionDownEvent(map, cursorState);

    movePotionDownEvent.execute();
    ASSERT_EQ(cursorState->getPotionsCursor(), 3);
}