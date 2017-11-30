#include "Obstacle.h"

Obstacle::woodBox(int X, int Y){
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	lcd.fillRect(gridFH.GridF(X), gridFH.GridF(Y), 16, 16, RGB( 170, 131, 71));
	lcd.drawRect((gridFH.GridF(X)+3), gridFH.GridF(Y), 2, 16, RGB(218,165,32));
	lcd.drawRect((gridFH.GridF(X)+7), gridFH.GridF(Y), 2, 16, RGB(218,165,32));
	lcd.drawRect((gridFH.GridF(X)+11), gridFH.GridF(Y), 2, 16, RGB(218,165,32));
	lcd.drawRect(gridFH.GridF(X), gridFH.GridF(Y), 16, 16, RGB(111, 82, 20));
}

Obstacle::ObstacleDR(int level)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	if(level == 1){
		woodBox(4,1);
		woodBox(7,1);
		woodBox(8,1);
		woodBox(9,1);
		woodBox(10,1);
		woodBox(3,2);
		woodBox(5,2);
		woodBox(7,2);
		woodBox(9,2);
		woodBox(11,2);
		woodBox(2,3);
		woodBox(4,3);
		woodBox(7,3);
		woodBox(8,3);
		woodBox(10,3);
		woodBox(11,3);
		woodBox(3,4);
		woodBox(5,4);
		woodBox(7,4);
		woodBox(9,4);
		woodBox(11,4);
		woodBox(13,4);
		woodBox(2,5);
		woodBox(3,5);
		woodBox(4,5);
		woodBox(5,5);
		woodBox(6,5);
		woodBox(7,5);
		woodBox(8,5);
		woodBox(9,5);
		woodBox(10,5);
		woodBox(12,5);
		woodBox(13,5);
		woodBox(1,6);
		woodBox(3,6);
		woodBox(5,6);
		woodBox(7,6);
		woodBox(11,6);
		woodBox(13,6);
		woodBox(1,7);
		woodBox(3,7);
		woodBox(4,7);
		woodBox(5,7);
		woodBox(6,7);
		woodBox(7,7);
		woodBox(8,7);
		woodBox(9,7);
		woodBox(10,7);
		woodBox(11,7);
		woodBox(12,7);
		woodBox(13,7);
		woodBox(1,8);
		woodBox(3,8);
		woodBox(5,8);
		woodBox(9,8);
		woodBox(11,8);
		woodBox(13,8);
		woodBox(2,9);
		woodBox(4,9);
		woodBox(5,9);
		woodBox(7,9);
		woodBox(9,9);
		woodBox(11,9);
		woodBox(12,9);
		woodBox(3,10);
		woodBox(9,10);
		woodBox(11,10);
		woodBox(4,11);
		woodBox(5,11);
		woodBox(6,11);
		woodBox(7,11);
		woodBox(9,11);
		woodBox(10,11);
		woodBox(1,12);
		woodBox(3,12);
		woodBox(5,12);
		woodBox(7,12);
		woodBox(9,12);
		woodBox(11,11);
		woodBox(2,13);
		woodBox(5,13);
		woodBox(7,13);
		woodBox(1,13);
		woodBox(10,13);
		woodBox(11,13);
	}
	else if (level == 2){
			woodBox(6,1);
			woodBox(7,1);
			woodBox(5,2);
			woodBox(7,2);
			woodBox(9,2);
			woodBox(4,3);
			woodBox(5,3);
			woodBox(6,3);
			woodBox(7,3);
			woodBox(8,3);
			woodBox(9,3);
			woodBox(10,3);
			woodBox(3,4);
			woodBox(5,4);
			woodBox(7,4);
			woodBox(9,4);
			woodBox(11,4);
			woodBox(1,5);
			woodBox(2,5);
			woodBox(3,5);
			woodBox(4,5);
			woodBox(5,5);
			woodBox(6,5);
			woodBox(7,5);
			woodBox(8,5);
			woodBox(9,5);
			woodBox(10,5);
			woodBox(11,5);
			woodBox(12,5);
			woodBox(13,5);
			woodBox(1,6);
			woodBox(3,6);
			woodBox(5,6);
			woodBox(7,6);
			woodBox(9,6);
			woodBox(11,6);
			woodBox(13,6);
			woodBox(1,7);
			woodBox(2,7);
			woodBox(3,7);
			woodBox(4,7);
			woodBox(5,7);
			woodBox(6,7);
			woodBox(7,7);
			woodBox(8,7);
			woodBox(9,7);
			woodBox(10,7);
			woodBox(11,7);
			woodBox(12,7);
			woodBox(13,7);
			woodBox(1,8);
			woodBox(3,8);
			woodBox(5,8);
			woodBox(7,8);
			woodBox(9,8);
			woodBox(11,8);
			woodBox(13,8);
			woodBox(1,9);
			woodBox(2,9);
			woodBox(3,9);
			woodBox(4,9);
			woodBox(5,9);
			woodBox(6,9);
			woodBox(7,9);
			woodBox(8,9);
			woodBox(9,9);
			woodBox(10,9);
			woodBox(11,9);
			woodBox(12,9);
			woodBox(13,9);
			woodBox(3,10);
			woodBox(5,10);
			woodBox(7,10);
			woodBox(9,10);
			woodBox(11,10);
			woodBox(4,11);
			woodBox(5,11);
			woodBox(6,11);
			woodBox(7,11);
			woodBox(8,11);
			woodBox(9,11);
			woodBox(10,11);
			woodBox(5,12);
			woodBox(7,12);
			woodBox(9,12);
			woodBox(6,13);
			woodBox(7,13);
			woodBox(8,13);
	}
	else if (level == 3){
	}
	else{
		lcd.fillScreen(RGB(255,255,255));
		lcd.drawText(20,20,"OW help some thing whent wrong pleas try again", RGB(255,0,0), RGB(255,255,255),5);
	}
} //Obstacle

Obstacle::OBcheck(int L, int X, int Y){
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	if(L == 1){
		
	}
	else if(L == 2){
		
	}
	else if (L == 3)
	{
		
	}
	else{
		lcd.drawText(20,20,"OW help some thing whent wrong pleas try again", RGB(255,0,0), RGB(255,255,255),5);
	}
}
