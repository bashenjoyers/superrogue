#include <gtest/gtest.h>
#include "Model/GameModel/Map/Map.h"
#include "Model/UIModel/Events/MovePotionUpEvent.h"
#include "Model/GameModel/GameObject/Character/Generation/AbstractEnemyFactory.h"
#include "Model/GameModel/GameObject/Character/Generation/FantasyEnemyFactory.h"
#include "Model/GameModel/Map/Generator/RandomGenerating/BinaryTreeMazeGenerator.h"
#include <memory>


TEST(MOVE_POTION_UP_EVENT_TESTS, TEST_EXECUTE) {
    std::shared_ptr<GameModel::Person> person = std::make_shared<GameModel::Person>();
    GameModel::Map::MapOptions mapOptions = GameModel::Map::MapOptions {
        .height = 24,
        .width = 24
    };
    int level = 1;

    std::shared_ptr<GameModel::Generation::ItemGenerator> itemGenerator = std::make_shared<GameModel::Generation::ItemGenerator>(level, person->get_full_characteristics().luck);
    std::shared_ptr<GameModel::Generation::Map::MapGenerator> mapGenerator = std::make_shared<GameModel::Generation::Map::BinaryTreeMazeGenerator>();
    std::shared_ptr<GameModel::Generation::AbstractEnemyFactory> enemyFactory = std::make_shared<GameModel::Generation::FantasyEnemyFactory>(level);
    std::shared_ptr<GameModel::Map::Map> map = std::make_shared<GameModel::Map::Map>(itemGenerator, mapGenerator, enemyFactory, person, mapOptions, 0);

    std::shared_ptr<UIModel::CursorState> cursorState = std::make_shared<UIModel::CursorState>();
    GameModel::Events::MovePotionUpEvent movePotionUpEvent = GameModel::Events::MovePotionUpEvent(map, cursorState);

    movePotionUpEvent.execute();
    ASSERT_EQ(cursorState->getPotionsCursor(), 1);
}