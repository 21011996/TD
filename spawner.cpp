#include "spawner.h"

namespace td{

	void Spawner::draw() {
		LabSetColor(LABCOLOR_CYAN);
		MyRect center(0, 0, 75, 75);
		center.drawFilled(m_x - 37, m_y - 37);

		MyRect border(0, 0, 75, 75);
		LabSetColor(LABCOLOR_BLACK);
		border.draw(m_x - 37, m_y - 37);
	}

	void Spawner::spawn() {
		Creep temporary(m_x, m_y, 10, 100, LABCOLOR_DARK_RED);
		m_units.push_back(temporary);
	}

	void Spawner::move_all() {
		for (int i = 0; i<m_units.size(); i++) {
			if (m_units[i].isAlive()) {
				m_units[i].move();
			} else {
				m_units.erase(m_units.begin() + i);
			}
		}
	}

	void Spawner::draw_all() {
		for (int i = 0; i<m_units.size(); i++) {
			m_units[i].draw();
		}
	}
}