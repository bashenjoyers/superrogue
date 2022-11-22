find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests
test.cpp
Model/GameModel/values.cpp
Model/GameModel/generator.cpp
Model/GameModel/GameManager.cpp
Model/GameModel/Map/Map.cpp
Model/GameModel/Map/Generator/MazeGenerator.cpp
Model/GameModel/Inventory/Inventory.cpp

# Controller tests
controller/eventProviderTests.cpp
Common/EnvironmentVariablesProviderTests.cpp
# UI model tests
Model/UIModel/CursorStateTests.cpp
Model/UIModel/Events/MoveEquipmentDownEventTests.cpp
Model/UIModel/Events/MoveEquipmentUpEventTests.cpp
Model/UIModel/Events/MovePotionDownEventTests.cpp
Model/UIModel/Events/MovePotionUpEventTests.cpp

# Exception tests
Model/Exceptions/exceptions.cpp
)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread Model)
