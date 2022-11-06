#pragma once

namespace superrogue {
struct Characteristics {
    int damage, armor, health, dexterity;
    float luck;
    Characteristics(int damage, int armor, int health, int dexterity, float luck) noexcept;
    Characteristics operator+ (Characteristics const &obj);
    Characteristics operator+= (Characteristics const &obj);
    // TODO *, *= for int koef
};
};
