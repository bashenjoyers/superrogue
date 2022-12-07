add_subdirectory(GameModel)
add_subdirectory(UIModel)

set(MODEL_SOURCES
        IEvent.cpp
        EmptyEvent.cpp

        Exceptions/exceptions.cpp
        GameModel/GameObject/Character/Class/Enemy/GreenHairReplicator.cpp GameModel/GameObject/Character/Class/Enemy/GreenHairReplicator.h GameModel/GameObject/Character/Class/Enemy/RedHairReplicator.cpp GameModel/GameObject/Character/Class/Enemy/RedHairReplicator.h GameModel/GameObject/Character/Class/Enemy/IReplicator.cpp GameModel/GameObject/Character/Class/Enemy/IReplicator.h)

add_library(Model ${MODEL_SOURCES} ${GAMEMODEL_SOURCES} ${UIMODEL_SOURCES})
