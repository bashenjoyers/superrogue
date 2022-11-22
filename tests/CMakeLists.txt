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
)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread Model)
