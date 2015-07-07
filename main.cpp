#include "labengine/labengine.h"


int main()
{
	LabInit();

	LabDrawLine(0, 0, LabGetWidth(), LabGetHeight());
	LabDrawFlush();

	LabInputKey();

	LabTerm();

	return 0;
}
