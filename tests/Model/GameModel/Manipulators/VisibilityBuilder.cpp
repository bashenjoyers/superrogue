#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include <memory>
#include <vector>
#include "Model/GameModel/Manipulators/VisibilityBuilder.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/abstract.h"
#include "Model/GameModel/GameManager.h"

using GameModel::Abstract::Position;
using GameModel::Map::VisibilityBuilder;
using GameModel::Map::World;
using GameModel::Map::MapOptions;
using GameModel::Person;
using GameModel::Abstract::MapEntity;
using GameModel::GameManager;
using GameModel::GameOptions;
using GameModel::CharacterAction;
using GameModel::Area;
using std::vector;


TEST(MODEL_GAME_MODEL, VISIBLE_CELLS_1) {
    auto person = std::make_shared<Person>();

    int width = 21;
    int height = 21;
    auto map = vector<vector<MapEntity>>(width, vector<MapEntity>(height, MapEntity::FLOOR));

    auto world = std::make_shared<World>(World{
	  .map_options = MapOptions {
        .height = height,
        .width = width,
      },
	  .enemies = {},
	  .person = person,
	  .map = map,
	  .door = Position {
        width - 1,
        height - 1,
      },
	  .items = {},
    });

    auto visibility_builder = VisibilityBuilder();
    visibility_builder.set_world(world);

    auto pos = Position(0, 0);
    person->set_position(pos);
    visibility_builder.set_pos(pos);

	visibility_builder.set_radius(1);
    ASSERT_EQ(visibility_builder.build().size(), 5);

    visibility_builder.set_radius(2);
    ASSERT_EQ(visibility_builder.build().size(), 10);

    visibility_builder.set_radius(3);
    for (auto cell: visibility_builder.build()) {
        std::cout << cell.pos.x << " " << cell.pos.y << "\n";
    }
    std::cout << "\n";
    ASSERT_EQ(visibility_builder.build().size(), 17);

    visibility_builder.set_radius(20);
    ASSERT_EQ(visibility_builder.build().size(), width * height);

    pos = Position(10, 10);
    person->set_position(pos);
    visibility_builder.set_pos(pos);
    visibility_builder.set_radius(1);
    ASSERT_EQ(visibility_builder.build().size(), 10);

    visibility_builder.set_radius(2);
    ASSERT_EQ(visibility_builder.build().size(), 26);

    visibility_builder.set_radius(3);
    ASSERT_EQ(visibility_builder.build().size(), 50);

    visibility_builder.set_radius(10);
    ASSERT_EQ(visibility_builder.build().size(), width * height);

    map[10][5] = MapEntity::ENEMY;  // -5 cells
    map[10][15] = MapEntity::WALL;  // -5 cells
    map[5][10] = MapEntity::ITEM;   // ignore
    map[15][10] = MapEntity::POTION;// ignore

    world = std::make_shared<World>(World{
	  .map_options = MapOptions {
        .height = height,
        .width = width,
      },
	  .enemies = {},
	  .person = person,
	  .map = map,
	  .door = Position {
        width - 1,
        height - 1,
      },
	  .items = {},
    });

    visibility_builder.set_world(world);
    visibility_builder.set_radius(10);
    ASSERT_EQ(visibility_builder.build().size(), width * height - 10);

    auto area = Area {
        .x1 = 8,
        .y1 = 10,
        .x2 = 12,
        .y2 = 21
    };
	visibility_builder.set_area(area);
    ASSERT_EQ(visibility_builder.build().size(), (12 - 8 + 1) * (20 - 10 + 1) - 5 + 1); // -5 because enemy, +1 - door

    visibility_builder.set_radius(5);
    ASSERT_EQ(visibility_builder.build().size(), (12 - 8 + 1) * (15 - 10 + 1) + 1);     // see enemy, no -1
    
    visibility_builder.set_radius(6);
    ASSERT_EQ(visibility_builder.build().size(), (12 - 8 + 1) * (16 - 10 + 1) - 1 + 1); // not see after enemy, -1
}


TEST(MODEL_GAME_MODEL, VISIBLE_CELLS_MAP_INFO) {
     auto options = MapOptions {
        .height = 100,
        .width = 100,
    };
    auto gm = GameManager(options);
    vector<CharacterAction> actions = {
        CharacterAction::STEP_FORWARD,
        CharacterAction::STEP_RIGHT,
        CharacterAction::STEP_BACK,
        CharacterAction::STEP_LEFT,
        CharacterAction::PUNCH_FORWARD,
        CharacterAction::PUNCH_RIGHT,
        CharacterAction::PUNCH_BACK,
        CharacterAction::PUNCH_LEFT,
        CharacterAction::POTION_1,
        CharacterAction::POTION_2,
        CharacterAction::POTION_3,
        CharacterAction::POTION_4,
        CharacterAction::POTION_5,
        CharacterAction::CHANGE_WEAPON,
        CharacterAction::CHANGE_ITEM,
        CharacterAction::WAIT
    };

    static std::uniform_int_distribution<int> action_gen(0, actions.size() - 1);
    std::mt19937 e;

    gm.generateMap();
    for (int i = 0; i < 10; i++) {
        int j = 0;
        while (!gm.isOver() && j < 100) {
            auto action = actions[action_gen(e)];
            gm.step(action);
            j++;
            auto info = gm.getMapInfo();
            ASSERT_GE(info.map_positions.size(), 4);    // corner case : person in (0, 0), enemies at (0, 1) and (1, 0), also see door
        }
    }
}
