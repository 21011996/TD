#include "towers.h"
#include "myMath.h"

namespace td{

	Tower::Tower(int x, int y, int damage, int range) {
		m_x = x;
		m_y = y;
		m_damage = damage;
		m_range = range;
	}

	void Tower::fire() {
		if (inRange(*m_target)) {
			m_missiles.push_back(Missile(m_x, m_y, 20, 50, m_target));
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

	void Tower::addTarget(Spawner & spawner) {
		if (spawner.getAmountOfCreeps()) {
			std::vector<Creep> &condidates = spawner.getCreeps();
			for (size_t i = 0; i< condidates.size(); i++) {
				if (inRange(condidates[i])) {
					m_target = &condidates[i];
					break;
				}
			}
		}
	}

	bool Tower::inRange(Creep & creep) {
		MyVector creep_position = creep.getPosition();
		MyVector tower_to_creep(creep_position.getX() - m_x, creep_position.getY());
		return (tower_to_creep.getLength() < m_range);
	}

	void Tower::draw() {
		LabSetColor(LABCOLOR_DARK_BLUE);
		MyRect center(0, 0, 80, 80);
		center.drawFilled(m_x - 40, m_y - 40);

		MyRect border(0, 0, 80, 80);
		LabSetColor(LABCOLOR_BLACK);
		border.draw(m_x - 40, m_y - 40);
	}

	void Tower::drawMissiles() {
		for (size_t i = 0; i< m_missiles.size(); i++) {
			m_missiles[i].draw();
		}
	}

	void Missile::draw() {
		LabSetColor(LABCOLOR_RED);
		MyRect center(0, 0, 10, 10);
		center.drawFilled(m_x - 5, m_y - 5);

		MyRect border(0, 0, 10, 10);
		LabSetColor(LABCOLOR_BLACK);
		border.draw(m_x - 5, m_y - 5);
	}

	void Missile::moveAt(int x, int y) {
		m_x += x;
		m_y += y;
	}

	void Missile::move() {
		if (!m_target->isAlive())
		{
			m_inProgress = false;
			return;
		}

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
}