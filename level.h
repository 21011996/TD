#pragma once
#include <vector>
#include "spawner.h"
#include "towers.h"
#include "navgrid.h"
#include "timer.h"

namespace td
{

struct Level
{
	Level(int x_size, int y_size);
	void draw();
	void live();
	void addTower(int x, int y);

private:
	int m_x_size, m_y_size;
	int m_health;
	bool m_alive;
	bool m_running;
	int m_level[10][8]; //dunno how to do it properly
	Grid m_grid;
	Cursor m_cursor;
	Timer m_timer;
	Spawner m_spawner;
	std::vector<Tower> m_towers;

};

} // namespace td
