#pragma once
#include "shapes.h"
#include <vector>
#include "units.h"

namespace td
{

struct Tower
{
	Tower(int x, int y, int damage, int speed, int range) : m_x(x), m_y(y), m_damage(damage), m_range(range) {};
	void fire();
	void moveMissiles();
	bool inRange(Creep creep);

private:
	int m_x, m_y, m_damage;
	int m_range;
	std::vector<Creep> m_targets;
	std::vector<Missile> m_missiles;
};

struct Missile
{
	Missile(int x, int y, int speed, Creep target) : m_x(x), m_y(y), m_speed(speed), m_target(target), m_inProgress(true) {};
	void move();

private:
	int m_x, m_y;
	int m_speed;
	bool m_inProgress;
	Creep m_target;
};


} // namespace td
