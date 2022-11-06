#pragma once
#include "model/game_object/item/IItem.h"
#include "model/const.h"
#include "exceptions/exceptions.h"

using superrogue::exception::GameObjectException;


namespace superrogue::game_object::item {
class Potion : public IItem {
    int __work_time;
public:
    Potion(string name, string description, Characteristics characteristics, int work_time);
    void step() noexcept;
    bool is_work() const noexcept;
};
};
