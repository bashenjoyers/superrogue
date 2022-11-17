#include "controller/CursorState.h"

namespace superrogue::controller {
    size_t CursorState::getPotionsCursor() {
        return potionsCursor;
    }

    game_object::item::ItemType CursorState::getEquipmentCursor() {
        return equipmentCursor;
    }

    void CursorState::incrementPotionsCursor() {
        potionsCursor = (potionsCursor + 1) % maxPotionsNumber;
    }

    void CursorState::decrementPotionsCursor() {
        potionsCursor = (potionsCursor - 1) % maxPotionsNumber;
    }

    void CursorState::incrementEquipmentCursor() {
        equipmentCursor = static_cast<game_object::item::ItemType>(
                ((int) equipmentCursor + 1) % maxEquipmentNumber
        );
    }

    void CursorState::decrementEquipmentCursor() {
        equipmentCursor = static_cast<game_object::item::ItemType>(
                ((int) equipmentCursor - 1) % maxEquipmentNumber
        );
    }
}

