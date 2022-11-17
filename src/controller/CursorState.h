#pragma once

#include <cstddef>
#include "model/game_object/item/stuff/Item.h"

namespace superrogue::controller {

    class CursorState {
    public:
        size_t getPotionsCursor();
        void incrementPotionsCursor();
        void decrementPotionsCursor();

        game_object::item::ItemType getEquipmentCursor();
        void incrementEquipmentCursor();
        void decrementEquipmentCursor();

    private:
        size_t potionsCursor = 0;
        game_object::item::ItemType equipmentCursor = game_object::item::ItemType::HELMET;
        size_t maxPotionsNumber = 3 + 1;
        int maxEquipmentNumber = static_cast<int>(game_object::item::ItemType::WEAPON_DISTANT) + 1;
    };
}

