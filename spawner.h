#pragma once

#include "shapes.h"
#include "units.h"
#include <vector>

namespace td
{

struct Spawner
{
	Spawner(int x, int y, int health, int speed) : m_x(x), m_y(y), m_health_default(health), m_speed(speed), m_damage_done(0), m_money_earned(0) {};
	Spawner(){};
	void draw(int size);

	void spawn();
	void move_all();
	void draw_all(int size);
	int getAmountOfCreeps(); // temp function fo debug
	int ask_for_damage();
	int ask_for_money();

	std::vector<Creep>& getCreeps();

private :
	int m_x, m_y;
	int m_money_earned;
	int m_speed, m_health_default;
	std::vector<Creep> m_units;
	int m_damage_done;
};

} // namespace td
