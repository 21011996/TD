#include "units.h"
#include "shapes.h"

namespace td{

	void Creep::draw() {
		MyLine toFill(0, 0, 50, 0);
		LabSetColor(m_color);

		for (int i = -25; i<25; i++) {
			toFill.draw(m_x, m_y + i);
		}

		MyRect border(0, 0, 50, 50);
		LabSetColor(LABCOLOR_BLACK);
		border.draw(m_x - 25, m_y - 25);
	}

	void Creep::damage(int dealt) {
		m_health -= dealt;
		if (m_health <= 0) {
			m_alive = false;
		}
	}

	bool Creep::isAlive() {
		return m_alive;
	}

	void Creep::move() {
		m_x += m_speed; //temporary movement
	}

}