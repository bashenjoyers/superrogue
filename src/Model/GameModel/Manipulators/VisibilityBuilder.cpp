#include <cassert>
#include "Model/GameModel/Manipulators/VisibilityBuilder.h"
#include "Model/GameModel/values.h"


namespace GameModel::Map {
VisibilityBuilder::VisibilityBuilder() {
    reset();
};

void VisibilityBuilder::reset() noexcept {
    pos = std::nullopt;
    radius = DEFAULT_VISIBLE_RADIUS;
    ignore_walls = false;
    area = Area();
    world = nullptr;
}

void VisibilityBuilder::set_pos(const Abstract::Position& pos) noexcept {
    this->pos = pos;
}

void VisibilityBuilder::set_radius(int radius) noexcept {
    this->radius = radius;
}

void VisibilityBuilder::set_ignore_walls(bool ignore_walls) noexcept {
    this->ignore_walls = ignore_walls;
}

void VisibilityBuilder::set_area(const Area& area) noexcept {
    this->area = area;
}

void VisibilityBuilder::set_world(std::shared_ptr<World> world) noexcept {
    this->world = world;
}

std::vector<GameModel::Abstract::MapEntityWithPosition> VisibilityBuilder::build() const {
    assert(world != nullptr);
    assert(pos.has_value());
    auto pos_ = pos.value();
    using Abstract::MapEntityWithPosition;
	using Abstract::Position;

	// std::vector<Abstract::MapEntityWithPosition> ans;
	// for (size_t y = 0; y < world->map.front().size(); y++) {
	// for (size_t x = 0; x < world->map.size(); x++) {
	// 	ans.push_back(MapEntityWithPosition{.pos = Position(x, y), .map_entity = world->map[x][y]});
	// }
	// }

	auto visible = std::vector<std::vector<bool>>(radius * 2 + 1, std::vector<bool>(radius * 2 + 1, false));
	int x = pos_.x;
	int y = pos_.y;

	int radius_x_pos = std::min(radius, (int)world->map.size() - 1 - x);
	int radius_x_neg = std::min(radius, x);
	int radius_y_pos = std::min(radius, (int)world->map.front().size() - 1 - y);
	int radius_y_neg = std::min(radius, y);

	std::vector<std::pair<int, int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
	for (auto direction : directions) {
		int radius_x = (direction.first > 0)? radius_x_pos : radius_x_neg;
		int radius_y = (direction.second > 0)? radius_y_pos : radius_y_neg;

		if (radius_x > 0) {
			int i = radius_x * direction.first;
			for (int j = 0; abs(j) <= radius_y; j += direction.second) {
				float del = abs((float)j/i);
				int dx = direction.first;
				int dy = 0;
				while (abs(dx) <= radius_x && abs(dy) <= radius_y) {
					if (Values::view_blockers.find(world->map[x + dx][y + dy]) == Values::view_blockers.end()) {
						visible[radius + dx][radius + dy] = true;
						if (abs((float)dy/dx) + EPS >= del) {
							dx += direction.first;
						} else {
							dy += direction.second;
						}
					} else {
						visible[radius + dx][radius + dy] = true;
						break;
					}
				}
			}
		}

		if (radius_y > 0) {
			int i = radius_y * direction.second;
			for (int j = 0; abs(j) <= radius_x; j += direction.first) {
				float del = abs((float)j/i);
				int dx = 0;
				int dy = direction.second;
				while (abs(dx) <= radius_x && abs(dy) <= radius_y) {
					if (Values::view_blockers.find(world->map[x + dx][y + dy]) == Values::view_blockers.end()) {
						visible[radius + dx][radius + dy] = true;
						if (abs((float)dx/dy) + EPS >= del) {
							dy += direction.second;
						} else {
							dx += direction.first;
						}
					} else {
						visible[radius + dx][radius + dy] = true;
						break;
					}
				}
			}
		}
	}

	auto door_pos = MapEntityWithPosition{
			.pos = Position(world->map.size()-1, world->map.front().size()-1),
			.map_entity = Abstract::MapEntity::DOOR,
	};

	auto own_pos = MapEntityWithPosition{
			.pos = pos_,
			.map_entity = world->map[pos_.x][pos_.y],
	};

	std::vector<MapEntityWithPosition> ans;
	ans.push_back(own_pos);
	ans.push_back(door_pos);

	std::optional<MapEntityWithPosition> enemy_pos = std::nullopt;
	if (world->person->get_settings().visible_enemy && world->enemies.size() > 0) {
		auto visible_enemy_pos = world->enemies.front()->get_position();
		enemy_pos = MapEntityWithPosition{
			.pos = visible_enemy_pos,
			.map_entity = world->map[visible_enemy_pos.x][visible_enemy_pos.y],
		};
		ans.push_back(enemy_pos.value());
	}

	for (int i = radius - radius_x_neg; i <= radius + radius_x_pos; i++) {
		for (int j = radius - radius_y_neg; j <= radius + radius_y_pos; j++) {
			if (visible[i][j]) {
				Position vpos = Position(i - radius + x, j - radius + y);
				if (vpos == door_pos.pos) continue;
				if (enemy_pos.has_value() && vpos == enemy_pos.value().pos) continue;
				if (area.x1 > vpos.x || area.y1 > vpos.y || area.x2 < vpos.x || area.y2 < vpos.y) continue;
				Abstract::MapEntity map_entity = world->map[i - radius + x][j - radius + y];
				if (map_entity == Abstract::MapEntity::PERSON) {
					float visible_k = world->person->get_settings().other_visible_k;
					if (std::max(abs((i - radius)), abs((j - radius))) > radius * visible_k) {
						map_entity = Abstract::MapEntity::FLOOR;
					}
				}
				ans.push_back(MapEntityWithPosition {
						.pos = vpos,
						.map_entity = map_entity,
				});
			}
		}
	}

	return ans;
}
}
