set(CONTROLLER_SOURCES
        EventProvider.cpp
        GameController.cpp

        Events/IEvent.cpp
        Events/EmptyEvent.cpp

        Events/UI/ActionUIEvent.cpp
        Events/UI/MoveEquipmentDownEvent.cpp
        Events/UI/MoveEquipmentUpEvent.cpp
        Events/UI/MovePotionDownEvent.cpp
        Events/UI/MovePotionUpEvent.cpp
        # EVENTS
        Events/Game/ChangeItemModelEvent.cpp
        Events/Game/ChangeWeaponModelEvent.cpp
        Events/Game/PotionModelEvent.cpp
        Events/Game/PunchBackModelEvent.cpp
        Events/Game/PunchForwardModelEvent.cpp
        Events/Game/PunchLeftModelEvent.cpp
        Events/Game/PunchRightModelEvent.cpp

        Events/Game/StepBackModelEvent.cpp
        Events/Game/StepForwardModelEvent.cpp
        Events/Game/StepLeftModelEvent.cpp
        Events/Game/StepRightModelEvent.cpp

        Events/Game/WaitModelEvent.cpp

        ModelViewDataConverter.cpp
)


add_library(Controller ${CONTROLLER_SOURCES})
target_link_libraries(Controller Model View Common)