#include "myMath.h"

namespace td{





	float MyVector::getX() {
		return m_x;
	}

	float MyVector::getY() {
		return m_y;
	}

	float MyVector::getLength() {
		return m_length;
	}

	MyVector MyVector::getNormilized() {
		float t_x = m_x/m_length, t_y = m_y/m_length;
		return MyVector(t_x, t_y);
	}
}