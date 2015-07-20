#include "towerBase.h"

namespace td{

	bool TowerBase::inRange(Creep & creep) {
		MyVector creep_position = creep.getPosition();
		MyVector tower_to_creep(creep_position.getX() - m_x, creep_position.getY() - m_y);
		return (tower_to_creep.getLength() < m_range);
	}

	void TowerBase::addTarget(Spawner & spawner) {
		if (spawner.getAmountOfCreeps() > 0) {
			std::vector<Creep> &condidates = spawner.getCreeps();
			for (size_t i = 0; i< condidates.size(); i++) {
				if (inRange(condidates[i])) {
					m_targets.push_back(&condidates[i]);
				}
			}
		}
	}

	void TowerBase::draw(int size){
		LabSetColor(m_color);
		MyRect center(0, 0, 80*size/100, 80*size/100);
		center.drawFilled(m_x - 80*size/200, m_y - 80*size/200);

		MyRect border(0, 0, 80*size/100, 80*size/100);
		LabSetColor(LABCOLOR_BLACK);
		border.draw(m_x - 80*size/200, m_y - 80*size/200);

		drawMissiles(size);
	}

}