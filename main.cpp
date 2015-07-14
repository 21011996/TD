#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>

#include "level.h"
#include "labengine/labengine.h"

using namespace td;

int main()
{

	labparams_t lab = {1000,800,1};
	LabInitWith(&lab);
	
	Level level(10, 8);
	level.live();
	

	LabTerm();
	return 0;
}