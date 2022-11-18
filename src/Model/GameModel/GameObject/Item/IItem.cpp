#include "IItem.h"
#include <iostream>
#include <string>

GameModel::IItem::IItem(std::string name,
                                            std::string description,
                                            Characteristics characteristics)
    : IGameObject(name, description, characteristics) {}
