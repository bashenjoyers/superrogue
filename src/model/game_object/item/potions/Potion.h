#pragma once
#include "model/game_object/item/IItem.h"
#include "model/const.h"
#include "exceptions/exceptions.h"


namespace superrogue::game_object::item {
class Potion : public IItem {
    int work_time;
public:
    Potion(std::string name, std::string description, Characteristics characteristics, int work_time);
    void step() noexcept;
    bool is_work() const noexcept;
};
};
