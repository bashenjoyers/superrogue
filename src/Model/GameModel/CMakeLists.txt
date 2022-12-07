set(GAMEMODEL_SOURCES
        GameModel/GameManager.cpp

        # EVENTS
        GameModel/Events/ChangeItemModelEvent.cpp
        GameModel/Events/ChangeWeaponModelEvent.cpp
        GameModel/Events/PotionModelEvent.cpp
        GameModel/Events/PunchBackModelEvent.cpp
        GameModel/Events/PunchForwardModelEvent.cpp
        GameModel/Events/PunchLeftModelEvent.cpp
        GameModel/Events/PunchRightModelEvent.cpp

        GameModel/Events/StepBackModelEvent.cpp
        GameModel/Events/StepForwardModelEvent.cpp
        GameModel/Events/StepLeftModelEvent.cpp
        GameModel/Events/StepRightModelEvent.cpp

        GameModel/Events/WaitModelEvent.cpp

        # GAME OBJECTS
        GameModel/GameObject/Characteristics.cpp
        GameModel/GameObject/IGameObject.cpp
        GameModel/GameObject/Character/Enemy.cpp
        GameModel/GameObject/Character/ICharacter.cpp
        GameModel/GameObject/Character/IConfusionEnemy.cpp
        GameModel/GameObject/Character/IEnemy.cpp
        GameModel/GameObject/Character/IPerson.cpp
        GameModel/GameObject/Character/Person.cpp

        GameModel/GameObject/Character/Class/ICharacterClass.cpp
        GameModel/GameObject/Character/Class/Person/Alchemist.cpp
        GameModel/GameObject/Character/Class/Person/Farsighted.cpp
        GameModel/GameObject/Character/Class/Person/Lucky.cpp
        GameModel/GameObject/Character/Class/Person/Secretive.cpp
        GameModel/GameObject/Character/Class/Person/Wise.cpp

        GameModel/GameObject/Character/Class/Enemy/IEnemyClass.cpp
        GameModel/GameObject/Character/Class/Enemy/Agressive.cpp
        GameModel/GameObject/Character/Class/Enemy/Flying.cpp
        GameModel/GameObject/Character/Class/Enemy/Indifferent.cpp
        GameModel/GameObject/Character/Class/Enemy/Ordinary.cpp
        GameModel/GameObject/Character/Class/Enemy/Coward.cpp
        GameModel/GameObject/Character/Class/Enemy/Traveler.cpp

        GameModel/GameObject/Character/Class/Enemy/state/behaviors.cpp
        GameModel/GameObject/Character/Class/Enemy/state/EnemyState.cpp
        GameModel/GameObject/Character/Class/Enemy/state/helpers.cpp

        GameModel/GameObject/Character/Generation/AbstractEnemyFactory.cpp
        GameModel/GameObject/Character/Generation/FantasyEnemyFactory.cpp

        GameModel/GameObject/Item/IItem.cpp
        GameModel/GameObject/Item/Stuff/Item.cpp
        GameModel/GameObject/Item/Potions/Potion.cpp
        GameModel/GameObject/Item/Generation/ItemGenerator.cpp

        # INVENTORY
        GameModel/Inventory/Inventory.cpp

        # MAP
        GameModel/Map/World.cpp
        GameModel/Map/Generator/RandomGenerating/BinaryTreeMazeGenerator.cpp
        GameModel/Map/MapBuilder.cpp
        GameModel/Manipulators/WorldManipulator.cpp

        PARENT_SCOPE
)