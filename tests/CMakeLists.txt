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
Controller/eventProviderTests.cpp
Common/EnvironmentVariablesProviderTests.cpp
# UI model tests
Model/UIModel/CursorStateTests.cpp
Model/UIModel/Events/MoveEquipmentDownEventTests.cpp
Model/UIModel/Events/MoveEquipmentUpEventTests.cpp
Model/UIModel/Events/MovePotionDownEventTests.cpp
Model/UIModel/Events/MovePotionUpEventTests.cpp
#Game model tests
Model/GameModel/GameObject/Item/Stuff/ItemTests.cpp
Model/GameModel/GameObject/Item/Potions/PotionTests.cpp

# Exception tests
Model/Exceptions/exceptions.cpp Model/GameModel/GameObject/Character/PersonTests.cpp Model/GameModel/GameObject/Character/EnemyTests.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread Model Controller)
