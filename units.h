#pragma once
#include "shapes.h"
#include "labengine\labengine.h"

namespace td
{

struct Creep
{
	Creep(int x, int y, int speed, int health, labcolor_t color) : m_x(x), m_y(y), m_speed(speed), m_health(health), m_color(color), m_alive(true) {};
	void draw();

	void damage(int dealt);
	bool isAlive();
	void move();
	

private :
	int m_x, m_y, m_speed, m_health;
	labcolor_t m_color;
	bool m_alive;
};

} // namespace td
