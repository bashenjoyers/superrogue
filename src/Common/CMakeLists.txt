set(COMMON_SOURCES
        Ncurses/CursesAPI.cpp
        environmentVariables/EnvironmentVariablesProvider.cpp
)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_library(Common ${COMMON_SOURCES})
target_link_libraries(Common ${CURSES_LIBRARIES})