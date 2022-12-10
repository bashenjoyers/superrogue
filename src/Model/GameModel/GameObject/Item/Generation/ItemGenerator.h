#pragma once

#include <cstddef>
#include <memory>
#include <random>

#include "Model/GameModel/GameObject/Item/IItem.h"
#include "Model/GameModel/values.h"
#include "Model/GameModel/Generator.h"

namespace GameModel::Generation {
class ItemGenerator : public Generator {
public:
    ItemGenerator(size_t level, float luck);

    std::shared_ptr<IItem> generate();

private:
    bool isDrop();
    std::shared_ptr<IItem> pickItem();

    std::uniform_real_distribution<float> dropDecider;
    std::uniform_int_distribution<size_t> itemPicker;
    std::random_device e; // std::mt19937 e;

    size_t totalItemsCount = Values::items_types.size() + Values::potions_types.size() - 1;

    size_t level;
    float luck;
};
}