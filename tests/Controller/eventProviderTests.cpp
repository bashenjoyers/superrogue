#include <gtest/gtest.h>
#include "Controller/EventProvider.h"
#include "Controller/Events/Game/PunchBackModelEvent.h"
#include "Controller/Events/Game/PunchForwardModelEvent.h"
#include "Controller/Events/Game/PunchLeftModelEvent.h"
#include "Controller/Events/Game/PunchRightModelEvent.h"
#include "Controller/Events/Game/StepBackModelEvent.h"
#include "Controller/Events/UI/MovePotionDownEvent.h"
#include "Controller/Events/UI/MovePotionUpEvent.h"
#include "Controller/Events/Game/StepForwardModelEvent.h"
#include "Controller/Events/Game/StepLeftModelEvent.h"
#include "Controller/Events/Game/StepRightModelEvent.h"
#include "Controller/Events/Game/ChangeWeaponModelEvent.h"
#include "Controller/Events/Game/ChangeItemModelEvent.h"
#include "Controller/Events/Game/PotionModelEvent.h"
#include "Controller/Events/Game/WaitModelEvent.h"
#include "Controller/Events/UI/MoveEquipmentDownEvent.h"
#include "Controller/Events/UI/MoveEquipmentUpEvent.h"


TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_W) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('w');
    ASSERT_TRUE(dynamic_cast<Controller::Events::PunchForwardModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_A) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('a');
    ASSERT_TRUE(dynamic_cast<Controller::Events::PunchLeftModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_S) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('s');
    ASSERT_TRUE(dynamic_cast<Controller::Events::PunchBackModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_D) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('d');
    ASSERT_TRUE(dynamic_cast<Controller::Events::PunchRightModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_Q) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('q');
    ASSERT_TRUE(dynamic_cast<Controller::Events::ChangeWeaponModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_L) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('l');
    ASSERT_TRUE(dynamic_cast<Controller::Events::StepBackModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_O) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('o');
    ASSERT_TRUE(dynamic_cast<Controller::Events::StepForwardModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_K) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('k');
    ASSERT_TRUE(dynamic_cast<Controller::Events::StepLeftModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_SEMICOLON) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey(';');
    ASSERT_TRUE(dynamic_cast<Controller::Events::StepRightModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_E) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('e');
    ASSERT_TRUE(dynamic_cast<Controller::Events::ChangeItemModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_P) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('p');
    ASSERT_TRUE(dynamic_cast<Controller::Events::PotionModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_DOT) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('.');
    ASSERT_TRUE(dynamic_cast<Controller::Events::WaitModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_MINUS) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('-');
    ASSERT_TRUE(dynamic_cast<Controller::Events::MoveEquipmentDownEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_EQUALS) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('=');
    ASSERT_TRUE(dynamic_cast<Controller::Events::MoveEquipmentUpEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_LEFT_SQUARE_BRACKET) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey(']');
    ASSERT_TRUE(dynamic_cast<Controller::Events::MovePotionUpEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_EQUALS_IF_RIGHT_SQUARE_BRACKET) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
  std::shared_ptr<GameModel::GameManager> gm = std::make_shared<GameModel::GameManager>(GameModel::Map::MapOptions {20, 20});
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, gm);

    auto result = eventProvider.getEventByKey('[');
    ASSERT_TRUE(dynamic_cast<Controller::Events::MovePotionDownEvent*>(&(*result)) != nullptr);
}