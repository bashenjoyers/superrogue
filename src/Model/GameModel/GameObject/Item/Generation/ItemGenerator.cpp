#include "ItemGenerator.h"

std::shared_ptr<GameModel::IItem> GameModel::Generation::ItemGenerator::generate() {
    if (isDrop()) {
        return pickItem();
    }

    return nullptr;
}

GameModel::Generation::ItemGenerator::ItemGenerator(size_t level, float luck) : level(level), luck(luck), Generator() /*e(randomDevice())*/ {
    dropDecider = std::uniform_real_distribution<float>(0, 1);  // uniform on [0, 1]
    itemPicker = std::uniform_int_distribution<size_t>(0, totalItemsCount);
}

bool GameModel::Generation::ItemGenerator::isDrop() {
    return dropDecider(e) < luck;
}

std::shared_ptr<GameModel::IItem> GameModel::Generation::ItemGenerator::pickItem() {
    size_t itemId = itemPicker(e);
    if (itemId >= Values::items_types.size()) {
        itemId -= Values::items_types.size();
        return Values::get_potion(Values::potions_types.at(itemId), level);
    }

    return Values::get_item(Values::items_types.at(itemId), level);
}
