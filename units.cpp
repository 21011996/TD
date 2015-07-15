#include "units.h"
#include "shapes.h"

namespace td{

	void Creep::draw(int size) {
		LabSetColor(LABCOLOR_DARK_RED);
		MyRect center(0, 0, 50*size/100, 50*size/100);
		center.drawFilled(m_x - 50*size/200, m_y - 50*size/200);

		LabSetColor(m_color);
		MyRect health(0, 0, (m_health*50*size/100/m_health_default), (m_health*50*size/100/m_health_default));
		health.drawFilled(m_x - 50*size/200, m_y - 50*size/200);

		MyRect border(0, 0, 50*size/100, 50*size/100);
		LabSetColor(LABCOLOR_BLACK);
		border.draw(m_x - 50*size/200, m_y - 50*size/200);
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

	bool Creep::reached() {
		return m_reached;
	}

	void Creep::move() {
		m_x += m_speed; //temporary movement
		if (m_x > LabGetWidth()) {
			m_alive = false;
			m_reached = true;
		}
	}

	MyVector Creep::getPosition() {
		return MyVector((float) m_x,(float) m_y);
	}

}