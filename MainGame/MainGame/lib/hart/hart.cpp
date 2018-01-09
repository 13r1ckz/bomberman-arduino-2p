/* 
* hart.cpp
*
* Created: 12/7/2017 11:26:13 AM
* Author: gerjo
*/

#include "hart.h"

#define RED 0xFFFFF800
#define WHITE 0xFFFFFFFF

/*
In deze functie het aantal hartjes getekend
*/
hart::HartS(int L, int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	int i;
	if(L == 3){
		drawHarts(X, Y);
		X++;
		drawHarts(X, Y);
		X++;
		drawHarts(X, Y);
	}
	else if(L == 2){
		drawHarts(X, Y);
		X++;
		drawHarts(X, Y);
		X++;
		lcd.fillRect(gridFH.GridF(X), gridFH.GridF(Y), 16, 16, WHITE);
		PORTC &=~(1<<PORTC3);				//Het groene ledje wordt uitgezet
	}
	else if(L == 1){
		drawHarts(X, Y);
		X++;
		lcd.fillRect(gridFH.GridF(X), gridFH.GridF(Y), 16, 16, WHITE);
		X++;
		lcd.fillRect(gridFH.GridF(X), gridFH.GridF(Y), 16, 16, WHITE);
		 PORTC &=~(1<<PORTC2);				//Het oranje ledje wordt uitgezet
	}
} 

/*
Met deze functie wordt een hartje getekend
*/
hart::drawHarts(int X, int Y){
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	
	lcd.drawLine((gridFH.GridF(X)+2), gridFH.GridF(Y), (gridFH.GridF(X)+4), gridFH.GridF(Y), RED);
	lcd.drawLine((gridFH.GridF(X)+8), gridFH.GridF(Y), (gridFH.GridF(X)+10), gridFH.GridF(Y), RED);
	lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+5), (gridFH.GridF(Y)+1), RED);
	lcd.drawLine((gridFH.GridF(X)+7), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+1), RED);
	lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+2), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+2), RED);
	lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+3), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+3), RED);
	lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+4), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+4), RED);
	lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+5), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+5), RED);
	lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+6), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+6), RED);
	lcd.drawLine((gridFH.GridF(X)+2), (gridFH.GridF(Y)+7), (gridFH.GridF(X)+10), (gridFH.GridF(Y)+7), RED);
	lcd.drawLine((gridFH.GridF(X)+3), (gridFH.GridF(Y)+8), (gridFH.GridF(X)+9), (gridFH.GridF(Y)+8), RED);
	lcd.drawLine((gridFH.GridF(X)+4), (gridFH.GridF(Y)+9), (gridFH.GridF(X)+8), (gridFH.GridF(Y)+9), RED);
	lcd.drawLine((gridFH.GridF(X)+5), (gridFH.GridF(Y)+10), (gridFH.GridF(X)+7), (gridFH.GridF(Y)+10), RED);
}