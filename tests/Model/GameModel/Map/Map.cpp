#include <gtest/gtest.h>
#include <random>
#include "Model/GameModel/GameManager.h"
#include "Model/GameModel/GameObject/Character/CharacterAction.h"

using std::vector;
using GameModel::GameManager;
using GameModel::Map::MapOptions;
using GameModel::Abstract::GameStatus;
using GameModel::CharacterAction;
using GameModel::Values::generator;


TEST(MODEL_GAME_MODEL, MAP__STEPS) {
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
        CharacterAction::CHANGE_ITEM,
        CharacterAction::WAIT
    };

    static std::uniform_int_distribution<int> action_gen(0, actions.size() - 1);
    for (int mi = 0; mi < 10; mi++) {
        auto map = gm.generate_map();
        for (int i = 0; i < 100; i++) {
            auto action = actions[action_gen(generator)];
            map->step(action);
            if (map->get_game_status() != GameStatus::IN_PROGRESS) break;
        }
    }
}
