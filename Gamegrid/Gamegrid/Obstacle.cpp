#include "Obstacle.h"

Obstacle::woodBox(int X, int Y){
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	lcd.fillRect(gridFH.GridF(X), gridFH.GridF(Y), 16, 16, RGB( 150, 111, 51));
	lcd.drawLine((gridFH.GridF(X)+1),(gridFH.GridF(Y)+1),(gridFH.GridF(X)+1),(gridFH.GridF(Y)+15), RGB(218,165,32));
	lcd.drawLine((gridFH.GridF(X)+3),(gridFH.GridF(Y)+1),(gridFH.GridF(X)+3),(gridFH.GridF(Y)+15), RGB(218,165,32));
	lcd.drawLine((gridFH.GridF(X)+5),(gridFH.GridF(Y)+1),(gridFH.GridF(X)+5),(gridFH.GridF(Y)+15), RGB(218,165,32));
	lcd.drawLine((gridFH.GridF(X)+7),(gridFH.GridF(Y)+1),(gridFH.GridF(X)+7),(gridFH.GridF(Y)+15), RGB(218,165,32));
	lcd.drawLine((gridFH.GridF(X)+9),(gridFH.GridF(Y)+1),(gridFH.GridF(X)+9),(gridFH.GridF(Y)+15), RGB(218,165,32));
	lcd.drawLine((gridFH.GridF(X)+11),(gridFH.GridF(Y)+1),(gridFH.GridF(X)+11),(gridFH.GridF(Y)+15), RGB(218,165,32));
	lcd.drawLine((gridFH.GridF(X)+13),(gridFH.GridF(Y)+1),(gridFH.GridF(X)+13),(gridFH.GridF(Y)+15), RGB(218,165,32));
}

Obstacle::ObstacleDR(int level)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	if(level == 1){
		woodBox(3,4);
		woodBox(5,4);
		woodBox(13,8);
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
