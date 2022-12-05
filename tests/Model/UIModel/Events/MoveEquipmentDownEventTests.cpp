#include <gtest/gtest.h>
#include "Model/GameModel/Map/Map.h"
#include "Model/UIModel/Events/MoveEquipmentDownEvent.h"
#include <memory>


// TEST(MOVE_EQUIPMENT_DOWN_EVENT_TESTS, TEST_EXECUTE) {
//     std::set<std::shared_ptr<GameModel::IEnemy>> enemies = std::set<std::shared_ptr<GameModel::IEnemy>>();
//     std::shared_ptr<GameModel::Person> person = std::make_shared<GameModel::Person>();
//     GameModel::Map::MapOptions mapOptions = GameModel::Map::MapOptions();
//     mapOptions.height = 24;
//     mapOptions.width = 24;
//     std::shared_ptr<GameModel::Map::Map> map = std::make_shared<GameModel::Map::Map>(enemies, person, mapOptions, 0);

//     std::shared_ptr<UIModel::CursorState> cursorState = std::make_shared<UIModel::CursorState>();
//     GameModel::Events::MoveEquipmentDownEvent moveEquipmentDownEvent = GameModel::Events::MoveEquipmentDownEvent(map, cursorState);

//     moveEquipmentDownEvent.execute();
//     ASSERT_EQ(cursorState->getEquipmentCursor(), GameModel::ItemType::WEAPON_DISTANT);
// }