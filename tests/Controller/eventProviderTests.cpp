#include <gtest/gtest.h>
#include "Controller/EventProvider.h"
#include "Model/GameModel/Events/PunchBackModelEvent.h"
#include "Model/GameModel/Events/PunchForwardModelEvent.h"
#include "Model/GameModel/Events/PunchLeftModelEvent.h"
#include "Model/GameModel/Events/PunchRightModelEvent.h"
#include "Model/GameModel/Events/StepBackModelEvent.h"
#include "Model/UIModel/Events/MovePotionDownEvent.h"
#include "Model/UIModel/Events/MovePotionUpEvent.h"
#include "Model/GameModel/Events/StepForwardModelEvent.h"
#include "Model/GameModel/Events/StepLeftModelEvent.h"
#include "Model/GameModel/Events/StepRightModelEvent.h"
#include "Model/GameModel/Events/ChangeWeaponModelEvent.h"
#include "Model/GameModel/Events/ChangeItemModelEvent.h"
#include "Model/GameModel/Events/PotionModelEvent.h"
#include "Model/GameModel/Events/WaitModelEvent.h"
#include "Model/UIModel/Events/MoveEquipmentDownEvent.h"
#include "Model/UIModel/Events/MoveEquipmentUpEvent.h"


TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_W) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('w');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::PunchForwardModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_A) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('a');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::PunchLeftModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_S) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('s');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::PunchBackModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_D) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('d');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::PunchRightModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_Q) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('q');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::ChangeWeaponModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_L) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('l');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::StepBackModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_O) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('o');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::StepForwardModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_K) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('k');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::StepLeftModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_SEMICOLON) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey(';');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::StepRightModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_E) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('e');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::ChangeItemModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_P) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('p');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::PotionModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_DOT) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('.');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::WaitModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_MINUS) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('-');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::MoveEquipmentDownEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_EQUALS) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('=');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::MoveEquipmentUpEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_LEFT_SQUARE_BRACKET) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey(']');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::MovePotionUpEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_EQUALS_IF_RIGHT_SQUARE_BRACKET) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('[');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::MovePotionDownEvent*>(&(*result)) != nullptr);
}