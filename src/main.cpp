#include "model/GameManager.h"
#include "model/map/Map.h"
#include "model/values.h"
#include <iostream>
#include <string>

#include "view/Curses/CursesFactory.h"

#include "model/inventory/Inventory.h"

using std::cout;
using std::string;
using superrogue::PotionType;
using superrogue::game_manager::GameManager;
using superrogue::game_object::item::Potion;
using superrogue::map::MapOptions;


using namespace superrogue::view;
using namespace superrogue::inventory;

#include "Boot.h"

int main() {
  Boot b;
  b.play();
}