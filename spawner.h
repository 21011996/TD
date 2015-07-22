#pragma once

#include "shapes.h"
#include "units.h"
#include "timer.h"
#include <vector>

namespace td
{

struct Spawner
{
	Spawner(int x, int y, int health, int speed, double spawn_rate);
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
	Timer m_timer;
	double m_last_spawn, m_last_move;
	double m_spawn_rate;
	std::vector<Creep> m_units;
	int m_damage_done;
};

} // namespace td
