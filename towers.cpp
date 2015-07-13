#include "towers.h"
#include "myMath.h"

namespace td{
	void Tower::fire() {
		if (!m_targets.empty()) {
			m_missiles.push_back(Missile(m_x, m_y, 10, m_targets[0]));
		}
	}

	void Tower::moveMissiles() {
		for (int i = 0; i<m_missiles.size(); i++) {
			m_missiles[i].move();
		}
	}

}