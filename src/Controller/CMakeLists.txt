set(CONTROLLER_SOURCES
        EventProvider.cpp
        GameController.cpp
)

add_library(Controller ${CONTROLLER_SOURCES})
target_link_libraries(Controller Model Common)