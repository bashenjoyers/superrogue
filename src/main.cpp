#include <iostream>
#include <string>
#include "model/values.h"

using std::cout;
using std::string;
using superrogue::game_object::item::Potion;
using superrogue::values::potions;
using superrogue::PotionType;


int main() {
    Potion potion = potions.at(PotionType::DAMAGE_POTION);
    cout << potion.get_description() << ", " << potion.get_name() << "\n";
    return 0;
}
