#pragma once

#include "shapes.h"
#include "timer.h" // prep for updated timer
#include "spawner.h"
#include "myMath.h"

namespace td{

struct TowerBase {
	bool inRange(Creep & creep);
	void addTarget(Spawner & spawner);

	void draw(int size);
	virtual void drawMissiles(int size) = 0;

	int m_x, m_y, m_damage, m_range;
	labcolor_t m_color;
	std::vector<Creep*> m_targets; 
};

} // namespace td
