#pragma once 

#include "../model/map/Map.h"
#include "../model/inventory/Inventory.h"

#include <memory>

namespace superrogue::view {

// TODO add I?
// TODO in common???
class ModelObserver {
public:
    virtual void handleEvent(std::shared_ptr<map::MapInfo> mapInfo) = 0;
};

class UIObserver {
public:
    virtual void handleEvent(size_t potionsCur, game_object::item::ItemType equipmentCur) = 0;
};

} // namespace superrogue
