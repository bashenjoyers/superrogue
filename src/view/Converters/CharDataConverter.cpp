#include "CharDataConverter.h"
#include <algorithm>


namespace superrogue::view
{

//TODO FIX
std::vector<std::vector<char>> CharConverter::convertMap(std::shared_ptr<map::Map> map)
{
    srand(time(NULL));
    size_t x = map->map.size();
    size_t y = map->map[0].size();

    std::vector<std::vector<char>> ans(x, std::vector<char>(y, '.'));
    std::transform(ans.begin(), ans.end(), ans.begin(), [](auto row) {
        std::transform(row.begin(), row.end(), row.begin(), [](char e) {
            return (char) rand();
        });

        return row;
    });
    return ans;
}

char CharConverter::convertItem(game_object::item::ItemType item)
{
    using game_object::item::ItemType;
    switch (item) {
        case ItemType::ARMOR : {
            return 'A';
        } break;

        case ItemType::BOOTS : {
            return 'B';
        } break;

        case ItemType::HELMET : {
            return 'H';
        } break;

        case ItemType::WEAPON_DISTANT : {
            return 'W';
        } break;

        case ItemType::WEAPON_MELEE : {
            return 'M';
        } break;

        default : {
            throw std::runtime_error("Unknown item type");  // TODO
        } break;
    }
}

char CharConverter::convertPotion() {
    return 'p';
}

char CharConverter::convertVoidItem() {
    return '$';
}

}