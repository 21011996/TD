#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#include "shapes.h"
#include "navgrid.h"
#include "labengine/labengine.h"
#include "spawner.h"
#include "towers.h"

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

	Spawner ololo(50, 350);
	Tower towerololo(350, 250, 10, 500);



	while (1) {
		LabClearWith(LABCOLOR_GREEN);

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
		if (ololo.getAmountOfCreeps() <= 5) {
			ololo.spawn();
		}
		ololo.move_all();
		towerololo.addTarget(ololo);
		towerololo.fire();
		towerololo.moveMissiles();
		LabDelay(10);
		ololo.draw();
		ololo.draw_all();
		towerololo.draw();
		towerololo.drawMissiles();
		grid.draw(cursor.get_x(), cursor.get_y());
		
		LabDrawFlush();
	}

	LabTerm();
	return 0;
}