set(VIEW_SOURCES
        Renderer.cpp
        Curses/CursesFactory.cpp
        Curses/CursesRenderer.cpp
        Converters/CharDataConverter.cpp
)

add_library(View ${VIEW_SOURCES})
target_link_libraries(View Common Model)