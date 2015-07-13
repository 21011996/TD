#include "units.h"
#include "shapes.h"

namespace td{

	void Creep::draw() {
		LabSetColor(m_color);
		MyRect center(0, 0, 50, 50);
		center.drawFilled(m_x - 25, m_y - 25);

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
		if (m_x > LabGetWidth()) {
			m_alive = false;
		}
	}

	MyVector Creep::getPosition() {
		return MyVector(m_x, m_y);
	}

}