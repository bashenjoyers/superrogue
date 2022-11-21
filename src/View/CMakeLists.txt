set(VIEW_SOURCES
        Curses/CursesRenderer.cpp
        Curses/CursesSubRenderer.cpp
        Converters/CharDataConverter.cpp
)

add_library(View ${VIEW_SOURCES})
target_link_libraries(View Common Model)