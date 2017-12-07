#include "Wall.h"

// default constructor
int OuterWall::OuterWallP()
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	
		int i , j;
		int X = 0;
		int Y = 0;
		
		for(i = 0; i < 15; i++){
			lcd.fillRect(gridFH.GridF(X),gridFH.GridF(Y),16,16, 0xFFFFFF);
			lcd.fillRect((gridFH.GridF(X)+1),(gridFH.GridF(Y)+1),14,14, 0x000);
			X = X + 1;
		}
		for(i = 0; i < 16; i++){
			lcd.fillRect(0,gridFH.GridF(Y),16,16, 0xFFFFFF);
			lcd.fillRect(1,(gridFH.GridF(Y)+1),14,14, 0x000);
			lcd.fillRect(224,gridFH.GridF(Y),16,16, 0xFFFFFF);
			lcd.fillRect(225,(gridFH.GridF(Y)+1),14,14, 0x000);
			Y = Y + 1;
		}
		X = 0;
		for(i = 0; i < 15; i++){
			lcd.fillRect(gridFH.GridF(X),224,16,16, 0xFFFFFF);
			lcd.fillRect((gridFH.GridF(X)+1),(225),14,14, 0x000);
			X = X + 1;
		}

} //OuterWall

int InnerWall::InnerWallP()
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	
	int i, j, X, Y, a;
	int x;
	int y;
	X = 2;
	Y = 2;
	for(i = 0; i < 6; i++){
		for(j = 0; j < 6; j++){
			lcd.fillRect((gridFH.GridF(X)),(gridFH.GridF(Y)),16,16, 0x000);
			X = X + 2;
		}
		X = 2;
		Y = Y + 2;
	}
} //InnerWall