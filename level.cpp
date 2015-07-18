#include "level.h"
#include <iostream>

namespace td{
	Level::Level(int x_size, int y_size) {
		m_x_size = x_size;
		m_y_size = y_size;
		m_health = 30;
		m_money = 2;
		m_running = false;
		m_alive = true;

		m_grid = Grid(m_x_size, m_y_size, LabGetWidth() / m_x_size);
		m_grid.set_opacity(1);
		m_cursor = Cursor(0, 0, m_x_size, m_y_size);

		m_spawner = Spawner(50, LabGetHeight() / 2, 400, 2);
		m_timer = Timer(0);

		for (int i = 0; i<m_x_size; i++) {
			for (int j = 0; j<m_y_size; j++) {
				m_level[i][j] = 0; //1 = road, 0 = grass, 2 = tower
			}
		} 
		for (int i = 0; i<m_x_size; i++) {
			for (int j = m_y_size/2-1; j<m_y_size/2+1; j++) {
				m_level[i][j] = 1; //1 = road, 0 = grass, 2 = tower
			}
		}
	}

	void Level::draw() {
		LabSetColorRGB(144, 238, 144);
		MyRect grass(0, 0, LabGetWidth(), LabGetHeight());
		grass.drawFilled(0, 0);

		LabSetColorRGB(139, 101, 8);
		MyRect road(0, 0, LabGetWidth(), LabGetWidth() / m_x_size * 2);
		road.drawFilled(0, LabGetHeight()/2 - LabGetWidth() / m_x_size);

		m_spawner.draw(LabGetWidth() / m_x_size);
		for (size_t i = 0; i<m_towers.size(); i++) {
			m_towers[i].draw(LabGetWidth() / m_x_size);
		}

		m_spawner.draw_all(LabGetWidth() / m_x_size);
		for (size_t i = 0; i<m_towers.size(); i++) {
			m_towers[i].drawMissiles(LabGetWidth() / m_x_size);
		}

		m_grid.draw(m_cursor.get_x(), m_cursor.get_y());

		LabDrawFlush();
	}

	void Level::writeStatus() {
		std::cout<<"                                                \r";
		if (m_alive) {
			std::cout<<"Health: ";
			std::cout<<m_health;
			std::cout<<" Money: ";
			std::cout<<m_money;
			std::cout<<"\r";
		} else {
			std::cout<<"Game Over, press ESC";
		}
	}

	void Level::addTower(int x, int y) {
		if ((m_level[x][y] == 0) && (m_money>0)) {
			m_towers.push_back(Tower((int) ((x+0.5) * m_grid.get_size()),(int) ((y+0.5) * m_grid.get_size()), 20, 500));
			m_level[x][y] = 2;
			m_money--;
			writeStatus();
		}
	}

	void Level::live() {
		while (1) {
			LabClear();
			if (LabInputKeyReady()) // key digestments
				{
					labkey_t key = LabInputKey();
					if (key == LABKEY_ESC) {
						LabTerm();
						break;
					}
					if (key == LABKEY_TAB) {
						if (m_running) {
							m_running = false;
						} else {
							m_running = true;
						}
					}
					if (key == LABKEY_ENTER) {
						addTower(m_cursor.get_x(), m_cursor.get_y());
					}
					if (key == LABKEY_BACK) {
						if (m_grid.get_opacity()) {
							m_grid.set_opacity(0);
						} else {
							m_grid.set_opacity(1);
						}
					}
					m_cursor.move(key);
				}
			
			if (m_running && m_alive) { // game process

				int damage_suffered = m_spawner.ask_for_damage();
				if (damage_suffered > 0) {
					m_health-=damage_suffered;
					if (m_health<=0) {
						m_alive = false;
					}
				}

				m_money += m_spawner.ask_for_money();
				writeStatus();


				if ((m_timer.getTime() % 100) == 0) {
					m_spawner.spawn();
				}

				for (size_t i = 0; i<m_towers.size(); i++) {
					m_towers[i].addTarget(m_spawner);
					m_towers[i].updateTarget();
				}
				for (size_t i = 0; i<m_towers.size(); i++) {
					if ((m_timer.getTime() % 20) == 0) {
						m_towers[i].fire();
					}
					if ((m_timer.getTime() % 1) == 0) {
						m_towers[i].moveMissiles();
					}
				}
				
				if ((m_timer.getTime() % 2) == 0) {
					m_spawner.move_all();
				}

				m_timer.tick();
			}

			

			draw();
		}
	}



}