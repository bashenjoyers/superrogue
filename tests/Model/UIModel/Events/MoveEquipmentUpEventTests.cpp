#include <gtest/gtest.h>
#include "Model/UIModel/Events/MoveEquipmentUpEvent.h"
#include "Model/GameModel/GameObject/Character/Generation/AbstractEnemyFactory.h"
#include "Model/GameModel/GameObject/Character/Generation/FantasyEnemyFactory.h"
#include "Model/GameModel/Map/Generator/RandomGenerating/BinaryTreeMazeGenerator.h"
#include <memory>


TEST(MOVE_EQUIPMENT_UP_EVENT_TESTS, TEST_EXECUTE) {
    std::shared_ptr<GameModel::Person> person = std::make_shared<GameModel::Person>();
    GameModel::Map::MapOptions mapOptions = GameModel::Map::MapOptions {
        .height = 24,
        .width = 24
    };
    int level = 1;

    std::shared_ptr<GameModel::Generation::ItemGenerator> itemGenerator = std::make_shared<GameModel::Generation::ItemGenerator>(level, person->get_full_characteristics().luck);
    std::shared_ptr<GameModel::Generation::Map::MapGenerator> mapGenerator = std::make_shared<GameModel::Generation::Map::BinaryTreeMazeGenerator>();
    std::shared_ptr<GameModel::Generation::AbstractEnemyFactory> enemyFactory = std::make_shared<GameModel::Generation::FantasyEnemyFactory>(level);
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(mapOptions);

    std::shared_ptr<UIModel::CursorState> cursorState = std::make_shared<UIModel::CursorState>();
    GameModel::Events::MoveEquipmentUpEvent moveEquipmentUpEvent = GameModel::Events::MoveEquipmentUpEvent(gm, cursorState);

    moveEquipmentUpEvent.execute();
    ASSERT_EQ(cursorState->getEquipmentCursor(), GameModel::ItemType::ARMOR);
}