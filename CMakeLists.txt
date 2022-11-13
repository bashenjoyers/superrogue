cmake_minimum_required(VERSION 3.11)

project(supperrogue)

set(CMAKE_CXX_STANDARD 20)

include_directories("src")

set(TARGET_NAME "${PROJECT_NAME}")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(
        ${PROJECT_NAME}
        src/main.cpp
        src/exceptions/exceptions.cpp
        src/exceptions/exceptions.h
        src/controller/IEvent.h
        src/controller/const.h
        src/model/abstract.h
        src/model/values.h
        src/model/GameManager.cpp
        src/model/GameManager.h
        src/model/const.h
        src/model/map/Map.h
        src/model/map/Map.cpp
        src/model/game_object/Characteristics.cpp
        src/model/game_object/Characteristics.h
        src/model/game_object/IGameObject.cpp
        src/model/game_object/IGameObject.h
        src/model/game_object/character/Person.h
        src/model/game_object/character/IEnemy.h
        src/model/game_object/character/ICharacter.cpp
        src/model/game_object/character/ICharacter.h
        src/model/game_object/character/Enemy.h
        src/model/game_object/character/IPerson.cpp
        src/model/game_object/character/CharacterAction.h
        src/model/game_object/character/Person.cpp
        src/model/game_object/character/IPerson.h
        src/model/game_object/character/Enemy.cpp
        src/model/game_object/character/IEnemy.cpp
        src/model/game_object/character/class/ICharacterClass.cpp
        src/model/game_object/character/class/ICharacterClass.h
        src/model/game_object/character/class/person/Lucky.h
        src/model/game_object/character/class/person/Lucky.cpp
        src/model/game_object/character/class/person/IPersonClass.h
        src/model/game_object/character/class/enemy/Ordinary.cpp
        src/model/game_object/character/class/enemy/IEnemyClass.h
        src/model/game_object/character/class/enemy/Ordinary.h
        src/model/game_object/item/IItem.h
        src/model/game_object/item/IItem.cpp
        src/model/game_object/item/potions/Potion.h
        src/model/game_object/item/potions/PotionType.h
        src/model/game_object/item/potions/Potion.cpp
        src/model/game_object/item/stuff/StuffType.h
        src/model/game_object/item/stuff/Item.h
        src/model/game_object/item/stuff/Item.cpp
        src/model/inventory/Inventory.h
        src/model/inventory/Inventory.cpp
        src/view/const.h
        src/view/Renderer.cpp
        src/view/Curses/CursesRenderer.cpp
        src/view/Curses/CursesFactory.cpp
        src/view/Curses/CursesAPI.cpp
        src/view/Converters/CharDataConverter.cpp
)
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})