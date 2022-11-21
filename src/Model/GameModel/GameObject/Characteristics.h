#pragma once

namespace GameModel {
/**
 * @brief a class with all possible characteristics of an object
 * 
 */
struct Characteristics {
  /** 
   * the meaning of the characteristics is clear from the name
   * 
   * // for creatures
   * damage calculation method:
   * if the attacker's dexterity is greater than the attacker's dexterity, then the chance to avoid is equivalent to 1 - (dexterity ratio)
   * otherwise, damage is dealt (health is subtracted) equal to the difference between the damage of the attacker and the armor of the attacked
   * if health drops to 0, then the creature dies. If this character the game ends, if the enemy, then he disappears from the map. An item or potion may appear in its place
   * 
   * luck - directly proportional to the probability with which things fall out of the enemy after killing
   * // for items
   * luck = 0
   * health != 0 only if a health potion was used
   * items change stats if they are equipped
   * potions temporarily change characteristics
   * characteristics of things depend on the level of the game
  */ 
  int damage, armor, health, dexterity;
  float luck;
  Characteristics(int damage = 0, int armor = 0, int health = 0,
                  int dexterity = 0, float luck = 0);
  // operators for internal use
  Characteristics operator+(Characteristics const &obj);
  Characteristics operator+=(Characteristics const &obj);
  Characteristics operator*(const int k);
};
}; // namespace GameModel
