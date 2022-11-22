add_subdirectory(GameModel)
add_subdirectory(UIModel)

set(MODEL_SOURCES
        IEvent.cpp
        EmptyEvent.cpp

        Exceptions/exceptions.cpp
)

add_library(Model ${MODEL_SOURCES} ${GAMEMODEL_SOURCES} ${UIMODEL_SOURCES})
