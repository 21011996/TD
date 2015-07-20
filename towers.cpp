#include "towers.h"
#include "myMath.h"

namespace td{

	Tower::Tower(int x, int y, int damage, int range) {
		m_x = x;
		m_y = y;
		m_damage = damage;
		m_range = range;
		m_firing = false;
	}

	Creep* Tower::getTarget(){
		if
	}

	void Tower::fire() {
		if (m_firing) {
			if (inRange(*m_target)) {
				m_missiles.push_back(Missile(m_x, m_y, 4, m_damage, m_target));
			}
		}
	}

	void Tower::moveMissiles() {
		size_t i = 0;
		while (i < m_missiles.size()) {
			if (m_missiles[i].inProgress()) {
				m_missiles[i].move();
				i++;
			} else {
				m_missiles.erase(m_missiles.begin() + i);
			}
		}
	}

	void Tower::updateTarget() {
		size_t i = 0;
		while (i < m_missiles.size()) {
			if (m_missiles[i].inProgress()) {
				m_missiles[i].setNewTarget(m_target);
				i++;
			} else {
				m_missiles.erase(m_missiles.begin() + i);
			}
		}
	}

	void Tower::drawMissiles(int size) {
		for (size_t i = 0; i< m_missiles.size(); i++) {
			m_missiles[i].draw(size);
		}
	}

	void Missile::draw(int size) {
		LabSetColor(LABCOLOR_RED);
		MyRect center(0, 0, 10*size/100, 10*size/100);
		center.drawFilled(m_x - 10*size/200, m_y - 10*size/200);

		MyRect border(0, 0, 10*size/100, 10*size/100);
		LabSetColor(LABCOLOR_BLACK);
		border.draw(m_x - 10*size/200, m_y - 10*size/200);
	}

	void Missile::moveAt(int x, int y) {
		m_x += x;
		m_y += y;
	}

	void Missile::move() {
		MyVector target_vector = m_target->getPosition();
		MyVector to(target_vector.getX() - m_x, target_vector.getY() - m_y);
		MyVector normal_to = to.getNormilized();
		if (m_speed > to.getLength()) {
			m_target->damage(m_damage);
			m_inProgress = false;
		} else {
			moveAt((int) (normal_to.getX()*m_speed),(int) (normal_to.getY()*m_speed));
		}
	}

	bool Missile::inProgress() {
		return m_inProgress;
	}

	void Missile::setNewTarget(Creep *target) {
		m_target = target;
	}
}