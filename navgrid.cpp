#include "navgrid.h"
#include "shapes.h"

namespace td {
	Grid::Grid(int num_cells_x, int num_cells_y, int cell_size) : m_cell_size(cell_size), m_num_cells_x(num_cells_x), m_num_cells_y(num_cells_y) {};

	void Grid::set_opacity(bool opacity) {
		m_opacity = opacity;
	}

	bool Grid::get_opacity() const {
		return m_opacity;
	}

	int Grid::get_size() {
		return m_cell_size;
	}

	void Grid::draw(int cursor_x, int cursor_y) const{
		if (m_opacity) {
			LabSetColor(LABCOLOR_WHITE);
			MyLine vertical_line(0, 0, 0, m_cell_size * m_num_cells_y);

			for (int i = 0; i<=m_num_cells_x; i++) {
				vertical_line.draw(i * m_cell_size, 0);
			}

			MyLine horizontal_line(0, 0, m_cell_size * m_num_cells_x, 0);

			for (int j = 0; j<=m_num_cells_y; j++) {
				horizontal_line.draw(0, j * m_cell_size);
			}
		}

		LabSetColor(LABCOLOR_RED);
		MyRect square(0, 0, m_cell_size, m_cell_size);

		square.draw(cursor_x * m_cell_size, cursor_y * m_cell_size);
	}

	Cursor::Cursor(int x, int y, int max_x, int max_y) : m_x(x), m_y(y), m_max_x(max_x), m_max_y(max_y) {};

	void Cursor::move(labkey_t key) {
		switch (key) 
		{
		case LABKEY_RIGHT :  
			{
				if (m_x < m_max_x - 1) {
					m_x++;
				}
				break;
			}
		case LABKEY_DOWN :
			{
				if (m_y < m_max_y - 1) {
					m_y++;
				}
				break;
			}
		case LABKEY_LEFT :
			{
				if (m_x > 0) {
					m_x--;
				}
				break;
			}
		case LABKEY_UP :
			{
				if (m_y > 0) {
					m_y--;
				}
				break;
			}
		}
	}

	void Cursor::get_pos(int &x, int &y) const {
		x = m_x;
		y = m_y;
	}

	int Cursor::get_x() const {
		return m_x;
	}

	int Cursor::get_y() const {
		return m_y;
	}
}