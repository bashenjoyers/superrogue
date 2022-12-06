add_subdirectory(GameModel)
add_subdirectory(UIModel)

set(MODEL_SOURCES
        IEvent.cpp
        EmptyEvent.cpp

        Exceptions/exceptions.cpp
        GameModel/GameObject/Character/Class/Enemy/Replicator.cpp GameModel/GameObject/Character/Class/Enemy/Replicator.h)

add_library(Model ${MODEL_SOURCES} ${GAMEMODEL_SOURCES} ${UIMODEL_SOURCES})
