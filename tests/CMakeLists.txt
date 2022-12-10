find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests
test.cpp
Model/GameModel/values.cpp
Model/GameModel/generator.cpp
Model/GameModel/GameManager.cpp
Model/GameModel/Manipulators/VisibilityBuilder.cpp
Model/GameModel/Map/Map.cpp
Model/GameModel/Map/MapBuilder.cpp
Model/GameModel/Map/Generator/MazeGenerator.cpp
Model/GameModel/Inventory/Inventory.cpp
Model/GameModel/GameObject/Item/Stuff/ItemTests.cpp
Model/GameModel/GameObject/Item/Potions/PotionTests.cpp

# Controller tests
Controller/eventProviderTests.cpp
Common/EnvironmentVariablesProviderTests.cpp
# UI model tests
Model/UIModel/CursorStateTests.cpp
Model/UIModel/Events/MoveEquipmentDownEventTests.cpp
Model/UIModel/Events/MoveEquipmentUpEventTests.cpp
Model/UIModel/Events/MovePotionDownEventTests.cpp
Model/UIModel/Events/MovePotionUpEventTests.cpp

# Exception tests
Model/Exceptions/exceptions.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread Model Controller)
