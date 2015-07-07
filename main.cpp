#include "labengine/labengine.h"
#include <cstdlib>

int x = 150;
int y = 400;
int speed = 0;
int a = 10;
double timePartition = 0.1; 

void setRandomColor(){
	LabSetColorRGB(rand() % 255, rand() % 255, rand() % 255); 
}

void updatePosition(){
	speed = speed + a*timePartition;
	y = y + speed*timePartition;
	if (y >= LabGetHeight() || y<= 0) {
		speed = -speed;
	}
	if (speed > 100) {
		speed = 0;
	}
}


int main()
{
	
	LabInit();

	while (1) {
		
		LabClear();
		setRandomColor();
		updatePosition();
		switch (rand() % 4)
		{
		case 0: LabDrawCircle(x,y,50);
		case 1: LabDrawEllipse(x+100,y,50,60);
		case 2: LabDrawLine(x+200,y,x+50,y+50);
		case 3: LabDrawPoint(x+300,y);
		case 4: LabDrawRectangle(x+400,y,x+50,y+50);
			break;
		}
		LabDrawFlush();
		LabDelay(10);
	}

	LabInputKey();
	LabTerm();

	return 0;
}
