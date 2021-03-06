#include "labengine/labengine.h"
#include "shapes.h"

namespace td
{

void MyLine::draw(int x, int y) {
	LabDrawLine(m_x1 + x, m_y1 + y, m_x2 + x, m_y2 + y);
}

void MyEllipse::draw(int x, int y) {
	LabDrawEllipse(m_x + x, m_y + y, m_a, m_b);
}

void MyRect::draw(int x, int y) {
	LabDrawRectangle(m_lx + x, m_ty + y, m_rx + x, m_by + y);
}

void MyRect::drawFilled(int x, int y) {
	MyLine line(m_lx, m_ty, m_rx, m_ty);

	for (int i = m_ty; i<m_by; i++) {
		line.draw(x, y + i);
	}
}

void MyPoint::draw(int x, int y) {
	LabDrawPoint(m_x + x, m_y + y);
}


} // namespace td
