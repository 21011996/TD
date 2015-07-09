#pragma once
#include "labengine/labengine.h"

namespace td
{

struct Grid
{
public :
	Grid(int num_cells_x, int num_cells_y, int cell_size);

	void draw(bool only_cursor, int cursor_x, int cursor_y) const;

private :
	int m_num_cells_x, m_num_cells_y, m_cell_size;
};

struct Cursor
{
public :
	Cursor(int x, int y, int max_x, int max_y);
	void move(labkey_t key);

	void get_pos(int &x, int &y) const;

private :
	int m_x, m_y, m_max_x, m_max_y;
};


} // namespace td
