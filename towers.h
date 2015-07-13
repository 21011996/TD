#pragma once
#include "shapes.h"
#include <vector>
#include "units.h"
#include "spawner.h"

namespace td
{

struct Missile
{
	Missile(int x, int y, int speed, int damage, Creep target) : m_x(x), m_y(y), m_speed(speed), m_damage(damage), m_target(target), m_inProgress(true) {};
	void move();
	void moveAt(int x, int y);

	bool inProgress();

	void draw();

private:
	int m_x, m_y;
	int m_speed;
	int m_damage;
	bool m_inProgress;
	Creep m_target;
};

struct Tower
{
	Tower(int x, int y, int damage, int range);
	void fire();
	void moveMissiles();
	bool inRange(Creep creep);
	void addTarget(Spawner spawner);

	void draw();
	void drawMissiles();

private:
	int m_x, m_y, m_damage;
	int m_range;
	Creep m_target;
	std::vector<Missile> m_missiles;
};




} // namespace td
