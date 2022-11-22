#include <gtest/gtest.h>
#include "controller/EventProvider.h"
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
#include "Model/GameModel/Events/ChangeItemModelEvent.h"
#include "Model/GameModel/Events/PotionModelEvent.h"
#include "Model/GameModel/Events/WaitModelEvent.h"
#include "Model/UIModel/Events/MoveEquipmentDownEvent.h"
#include "Model/UIModel/Events/MoveEquipmentUpEvent.h"


TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_W) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('w');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::PunchForwardModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_A) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('a');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::PunchLeftModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_S) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('s');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::PunchBackModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_D) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('d');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::PunchRightModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_K) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('k');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::StepBackModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_I) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('i');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::StepForwardModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_J) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('j');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::StepLeftModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_L) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('l');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::StepRightModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_E) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('e');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::ChangeItemModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_P) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('p');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::PotionModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_DOT) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('.');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::WaitModelEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_MINUS) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('-');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::MoveEquipmentDownEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_EQUALS) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('=');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::MoveEquipmentUpEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_LEFT_SQUARE_BRACKET) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey(']');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::MovePotionUpEvent*>(&(*result)) != nullptr);
}

TEST(EVENT_PROVIDER, GET_EVENT_BY_KEY_IF_EQUALS_IF_RIGHT_SQUARE_BRACKET) {
    std::shared_ptr<UIModel::CursorState> cursorState = std::shared_ptr<UIModel::CursorState>();
    std::shared_ptr<GameModel::Map::Map> map = std::shared_ptr<GameModel::Map::Map>();
    Controller::EventProvider eventProvider = Controller::EventProvider(cursorState, map);

    auto result = eventProvider.getEventByKey('[');
    ASSERT_TRUE(dynamic_cast<GameModel::Events::MovePotionDownEvent*>(&(*result)) != nullptr);
}