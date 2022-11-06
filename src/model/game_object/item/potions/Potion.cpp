#include <iostream>
#include <string>
#include "model/game_object/item/potions/Potion.h"
#include "model/const.h"
#include "exceptions/exceptions.h"


namespace superrogue::game_object::item {
Potion::Potion(string name, string description, Characteristics characteristics, int work_time = DEFAULT_POTION_WORK_TIME) : 
    IItem(name, description, characteristics), __work_time(work_time) {
        if (work_time < 0) {
            const string a = string("word_time should be more than 0");
            throw GameObjectException(a);
        }
    }

void Potion::step() noexcept {
    if (__work_time > 0) __work_time--;
}

bool Potion::is_work() const noexcept {
    return __work_time != 0;
}
};
