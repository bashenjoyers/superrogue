#include "model/GameManager.h"
#include "model/map/Map.h"
#include "model/values.h"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using superrogue::PotionType;
using superrogue::game_manager::GameManager;
using superrogue::game_object::item::Potion;
using superrogue::map::MapOptions;

int main() {
  // Potion potion = potions.at(PotionType::DAMAGE_POTION);
  // cout << potion.get_description() << ", " << potion.get_name() << "\n";
  auto map_options = MapOptions(200, 30);
  auto game_manager = GameManager(map_options);
  auto map = game_manager.generate_map();
  auto info = map.get_map_info();
  cout << "hero name=" << info.name << ", description=" << info.description
       << "\n";
  return 0;
}
