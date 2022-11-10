#include "CharDataConverter.h"
namespace superrogue::view
{

//TODO FIX
std::vector<std::vector<char>> CharConverter::convertMap(std::shared_ptr<map::Map> map)
{
    size_t x = map->map.size();
    size_t y = map->map[0].size();

    std::vector<std::vector<char>> ans(x, std::vector<char>(y, '.'));
    return ans;
}

char CharConverter::convertItem(game_object::item::ItemType item)
{
    return 'c';
}
}