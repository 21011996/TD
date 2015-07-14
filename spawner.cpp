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
		Creep temporary(m_x, m_y, m_speed, m_health_default, LABCOLOR_WHITE);
		m_units.push_back(temporary);
	}

	void Spawner::move_all() {
		size_t i = 0;
		while (i < m_units.size()) {
			if (m_units[i].isAlive()) {
				m_units[i].move();
				i++;
			} else {
				if (m_units[i].reached()) {
					m_damage_done+=1;
					m_units.erase(m_units.begin() + i);
				} else {
					m_units.erase(m_units.begin() + i);
				}
			}
		}
	}

	int Spawner::ask_for_damage() {
		int answer = m_damage_done;
		m_damage_done = 0;
		return answer;
	}
	void Spawner::draw_all() {
		for (size_t i = 0; i<m_units.size(); i++) {
			m_units[i].draw();
		}
	}

	int Spawner::getAmountOfCreeps() {
		return m_units.size();
	}

	std::vector<Creep>& Spawner::getCreeps() {
		return m_units;
	}
}