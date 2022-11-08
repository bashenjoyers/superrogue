#include "model/game_object/Characteristics.h"
#include "exceptions/exceptions.h"

using superrogue::exception::GameObjectException;


namespace superrogue {
Characteristics::Characteristics(int damage, int armor, int health, int dexterity, float luck) noexcept : 
    damage(damage), armor(armor), health(health), luck(luck), dexterity(dexterity) {}

Characteristics Characteristics::operator+ (Characteristics const &other)  {
    if (other.luck != 0) {
        throw GameObjectException("luck items should be 0");
    }
    return Characteristics(this->damage + other.damage, this->armor + other.armor, 
        this->health + other.health, this->dexterity + other.dexterity, this->luck);   // FIXME(health)
}

Characteristics Characteristics::operator+= (Characteristics const &other) {
    if (other.luck != 0) {
        throw GameObjectException("luck items should be 0");
    }
    this->damage += other.damage;
    this->armor += other.armor;
    this->health += other.health;
    this->dexterity += other.dexterity;
    return *this;
}

Characteristics Characteristics::operator* (const int k) {
    return Characteristics(damage * k, armor * k, health * k, dexterity * k, luck);
};
};
