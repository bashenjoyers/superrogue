cmake_minimum_required(VERSION 3.11)

project(superrogue)

set(CMAKE_CXX_STANDARD 20)

include_directories("src")

set(TARGET_NAME "${PROJECT_NAME}")

add_subdirectory(src/Common)
add_subdirectory(src/Model)
add_subdirectory(src/Controller)
add_subdirectory(src/View)

add_subdirectory(tests)

add_executable(superrogue src/main.cpp)
target_link_libraries(superrogue View Model Controller Common)
