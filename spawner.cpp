#include "spawner.h"

namespace td{

	Spawner::Spawner(int x, int y, int health, int speed, double spawn_rate) {
		m_x = x; 
		m_y = y; 
		m_health_default = health; 
		m_speed = speed; 
		m_damage_done = 0; 
		m_money_earned = 0; 
		m_spawn_rate = spawn_rate;
		m_timer = Timer();
		m_last_move = m_timer.getTime();
		m_last_spawn = m_timer.getTime();
	}

	void Spawner::draw(int size) {
		LabSetColor(LABCOLOR_CYAN);
		MyRect center(0, 0, 75*size/100, 75*size/100);
		center.drawFilled(m_x - 75*size/200, m_y - 75*size/200);

		MyRect border(0, 0, 75*size/100, 75*size/100);
		LabSetColor(LABCOLOR_BLACK);
		border.draw(m_x - 75*size/200, m_y - 75*size/200);
	}

	void Spawner::spawn() {
		if (m_timer.getDeltaTime(m_last_spawn) > m_spawn_rate) {
			Creep temporary(m_x, m_y, m_speed, m_health_default, LABCOLOR_WHITE);
			m_units.push_back(temporary);
			m_last_spawn = m_timer.getTime();
		}
	}

	void Spawner::move_all() {
		if (m_timer.getDeltaTime(m_last_move) > 3) {
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
						m_money_earned++;
						m_units.erase(m_units.begin() + i);
					}
				}
			}
			m_last_move = m_timer.getTime();
		}
	}

	int Spawner::ask_for_damage() {
		int answer = m_damage_done;
		m_damage_done = 0;
		return answer;
	}

	int Spawner::ask_for_money() {
		int answer = m_money_earned;
		m_money_earned = 0;
		return answer;
	}

	void Spawner::draw_all(int size) {
		for (size_t i = 0; i<m_units.size(); i++) {
			m_units[i].draw(size);
		}
	}

	int Spawner::getAmountOfCreeps() {
		return m_units.size();
	}

	std::vector<Creep>& Spawner::getCreeps() {
		return m_units;
	}
}