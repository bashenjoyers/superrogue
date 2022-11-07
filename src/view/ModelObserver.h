#pragma once 

#include "../model/map/Map.h"
#include "../model/inventory/Inventory.h"

#include <memory>

namespace superrogue::view {

// TODO add I?
// TODO in common???
class ModelObserver {
public:
    virtual void handleEvent(std::shared_ptr<map::Map> map, std::shared_ptr<inventory::Inventory> inv) = 0;
};

} // namespace superrogue
