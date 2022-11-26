#include <gtest/gtest.h>
#include "Model/Exceptions/exceptions.h"

const std::string exceptionMessage = "exception";

TEST(EXCEPTIONS, GAME_OBJECT_EXCEPTION) {
    GameObjectException gameObjectException = GameObjectException(exceptionMessage);
    ASSERT_EQ(gameObjectException.what(), exceptionMessage);
}

TEST(EXCEPTIONS, CONFIG_READ_EXCEPTION) {
    ConfigReadException configReadException = ConfigReadException(exceptionMessage);
    ASSERT_EQ(configReadException.what(), exceptionMessage);
}

TEST(EXCEPTIONS, INVENTORY_EXCEPTION) {
    InventoryException inventoryException = InventoryException(exceptionMessage);
    ASSERT_EQ(inventoryException.what(), exceptionMessage);
}

TEST(EXCEPTIONS, STEP_EXCEPTION) {
    StepException stepException = StepException(exceptionMessage);
    ASSERT_EQ(stepException.what(), exceptionMessage);
}

TEST(EXCEPTIONS, EVENT_EXCEPTION) {
    EventException eventException = EventException(exceptionMessage);
    ASSERT_EQ(eventException.what(), exceptionMessage);
}
