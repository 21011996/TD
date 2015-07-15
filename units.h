#pragma once
#include "shapes.h"
#include "labengine\labengine.h"
#include "myMath.h"

namespace td
{

struct Creep
{
	Creep(int x, int y, int speed, int health, labcolor_t color) : m_x(x), m_y(y), m_speed(speed), m_health(health), m_health_default(health), m_color(color), m_alive(true), m_reached(false) {};
	Creep(){};
	void draw(int size);

	void damage(int dealt);
	bool isAlive();
	void move();
	bool reached();

	MyVector getPosition();
	

private :
	int m_x, m_y, m_speed, m_health, m_health_default;
	labcolor_t m_color;
	bool m_alive, m_reached;
};

} // namespace td
