#pragma once

namespace superrogue {
struct Characteristics {
  int damage, armor, health, dexterity;
  float luck;
  Characteristics(int damage = 0, int armor = 0, int health = 0,
                  int dexterity = 0, float luck = 0);
  Characteristics operator+(Characteristics const &obj);
  Characteristics operator+=(Characteristics const &obj);
  Characteristics operator*(const int k);
};
}; // namespace superrogue
