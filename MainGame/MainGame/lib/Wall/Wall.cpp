#include "Wall.h"

#define BLACK 0x00000000
#define WHITE 0xFFFFFFFF

// default constructor
int OuterWall::OuterWallP()
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	
		int X = 0;
		int Y = 0;
		
		for(X = 0; X < 15; X++){
			lcd.fillRect(gridFH.GridF(X),gridFH.GridF(Y),16,16, WHITE);
			lcd.fillRect((gridFH.GridF(X)+1),(gridFH.GridF(Y)+1),14,14, BLACK);
		}
		for(Y = 0; Y < 16; Y++){
			lcd.fillRect(0,gridFH.GridF(Y),16,16, WHITE);
			lcd.fillRect(1,(gridFH.GridF(Y)+1),14,14, BLACK);
			lcd.fillRect(224,gridFH.GridF(Y),16,16, WHITE);
			lcd.fillRect(225,(gridFH.GridF(Y)+1),14,14, BLACK);
		}
		for(X = 0; X < 15; X++){
			lcd.fillRect(gridFH.GridF(X),224,16,16, WHITE);
			lcd.fillRect((gridFH.GridF(X)+1),(225),14,14, BLACK);
		}

} //OuterWall

int InnerWall::InnerWallP()
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	
	int X, Y;
	
	for(Y = 2; Y <= 12; Y+=2){
		for(X = 2; X <= 12; X+=2){
			lcd.fillRect((gridFH.GridF(X)),(gridFH.GridF(Y)),16,16, BLACK);
		}
	}
} //InnerWall