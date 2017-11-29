#include "Obstacle.h"

Obstacle::ObstacleDR(int level)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	if(level == 1){
		
		
	}
	else if (level == 2){
		
	}
	else if (level == 3){
	}
	else{
		lcd.fillScreen(RGB(255,255,255));
		lcd.drawText(20,20,"OW help some thing whent wrong pleas try again", RGB(255,0,0), RGB(255,255,255),5);
	}
} //Obstacle
