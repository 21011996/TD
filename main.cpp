#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#include "shapes.h"
#include "navgrid.h"
#include "labengine/labengine.h"

namespace 
{
} // namespace

using namespace td;

int main()
{

	labparams_t lab = {1000,800,1};
	LabInitWith(&lab);

	Grid grid(10,8,100);
	grid.set_opacity(1);
	Cursor cursor(0,0,10,8);


	while (1) {
		LabClear();

		if (LabInputKeyReady())
		{
			labkey_t key = LabInputKey();
			if (key == LABKEY_ESC) {
				break;
			}
			if (key == LABKEY_BACK) {
				if (grid.get_opacity()) {
					grid.set_opacity(0);
				} else {
					grid.set_opacity(1);
				}
			}
			cursor.move(key);
		}
		grid.draw(cursor.get_x(), cursor.get_y());
		
		LabDrawFlush();
	}

	LabTerm();
	return 0;
}