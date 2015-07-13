#pragma once

#include "shapes.h"
#include "units.h"
#include <vector>

namespace td
{

struct Spawner
{
	Spawner(int x, int y) : m_x(x), m_y(y) {};
	void draw();

	void spawn();
	void move_all();
	void draw_all();
	int getAmountOfCreeps(); // temp function fo debug

	std::vector<Creep> getCreeps();

private :
	int m_x, m_y;
	std::vector<Creep> m_units;
};

} // namespace td
