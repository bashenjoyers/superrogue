#include <gtest/gtest.h>
#include <random>
#include <memory>
#include "Model/GameModel/GameManager.h"
#include "Model/GameModel/Map/MapBuilder.h"
#include "Model/GameModel/GameObject/Character/Generation/FantasyEnemyFactory.h"
#include "Model/GameModel/GameObject/Item/Generation/ItemGenerator.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include "Model/GameModel/Map/Generator/RandomGenerating/BinaryTreeMazeGenerator.h"
#include "Model/GameModel/Map/MapOptions.h"


using GameModel::Generation::Map::MapBuilder;
using GameModel::Generation::Map::BinaryTreeMazeGenerator;
using GameModel::Generation::FantasyEnemyFactory;
using GameModel::Generation::ItemGenerator;
using GameModel::Person;
using GameModel::Map::MapOptions;


TEST(MODEL_GAME_MODEL, MAP_BUILDER__BUILD) {
    int level = 1;
    auto person = std::make_shared<Person>();
    auto enemyFactory = std::make_shared<FantasyEnemyFactory>(level);
    auto itemGenerator = std::make_shared<ItemGenerator>(level, person->get_full_characteristics().luck);
    auto mapGenerator = std::make_shared<BinaryTreeMazeGenerator>();
    int height = 20;
    int width = 25;
    auto map_options = MapOptions {
        .height = height,
        .width = width,
    };
    size_t enemyCount = 5;
    size_t itemsCount = 6;
    auto builder = std::make_shared<MapBuilder>();
    builder->setEnemiesFactory(enemyFactory);
    builder->setItemsGenerator(itemGenerator);
    builder->setMapGenerator(mapGenerator);
    builder->setMapOptions(map_options);
    builder->setEnemiesCount(enemyCount);
    builder->setItemsCount(itemsCount);
    builder->setPerson(person);
    auto world = builder->build();
    ASSERT_EQ(person, world.person);
    ASSERT_EQ(height - 1, world.door.y);
    ASSERT_EQ(width - 1, world.door.x);
    ASSERT_EQ(enemyCount, world.enemies.size());
    ASSERT_GE(itemsCount, world.items.size());
    ASSERT_EQ(map_options.height, world.map_options.height);
    ASSERT_EQ(map_options.width, world.map_options.width);
    ASSERT_EQ(width, world.map.size());
    ASSERT_EQ(height, world.map.front().size());

    itemGenerator = std::make_shared<ItemGenerator>(level, 0);
    builder->reset();
    builder->setEnemiesFactory(enemyFactory);
    builder->setItemsGenerator(itemGenerator);
    builder->setMapGenerator(mapGenerator);
    builder->setMapOptions(map_options);
    builder->setEnemiesCount(enemyCount);
    builder->setItemsCount(itemsCount);
    builder->setPerson(person);
    world = builder->build();
    ASSERT_EQ(person, world.person);
    ASSERT_EQ(height - 1, world.door.y);
    ASSERT_EQ(width - 1, world.door.x);
    ASSERT_EQ(enemyCount, world.enemies.size());
    ASSERT_EQ(0, world.items.size());
    ASSERT_EQ(map_options.height, world.map_options.height);
    ASSERT_EQ(map_options.width, world.map_options.width);
    ASSERT_EQ(width, world.map.size());
    ASSERT_EQ(height, world.map.front().size());

    builder->reset();
    map_options = MapOptions {
        .height = 25,
        .width = 20,
    };
    itemsCount = 100;
    builder->setItemsCount(100);
    builder->setMapOptions(map_options);
    world = builder->build();
    ASSERT_EQ(map_options.height - 1, world.door.y);
    ASSERT_EQ(map_options.width - 1, world.door.x);
    ASSERT_EQ(map_options.height, world.map_options.height);
    ASSERT_EQ(map_options.width, world.map_options.width);
    ASSERT_EQ(0, world.enemies.size());
    ASSERT_EQ(100, world.items.size());
    ASSERT_EQ(height, world.map.size());
    ASSERT_EQ(width, world.map.front().size());
}
