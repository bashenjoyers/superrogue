#include "World.h"
#include "Model/GameModel/values.h"
#include "Model/GameModel/Map/Generator/RandomGenerating/BinaryTreeMazeGenerator.h"
#include "Model/GameModel/GameObject/Character/Person.h"
#include <memory>

using std::max;
using std::optional;
using std::set;
using std::shared_ptr;
using std::vector;

namespace GameModel::Map {
using namespace Abstract;

MapInfo::MapInfo(vector <MapEntityWithPosition> map_positions,
				 std::shared_ptr<ICharacter> person_with_position, MapOptions mapOptions)
	: map_positions(map_positions), mapOptions(mapOptions) {
  auto person = dynamic_cast<Person *>(&*person_with_position);
  name = person->get_name();
  characteristics = person->get_full_characteristics();
  description = person->get_description();
  inventory = person->get_inventory_info();
  weapon_melee = person->is_weapon_melee();
}

}; // namespace GameModel::Map
