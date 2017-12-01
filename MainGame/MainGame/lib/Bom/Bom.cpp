/* 
* Bom.cpp
*
* Created: 11/30/2017 11:26:54 AM
* Author: gerjo
*/


#include "Bom.h"

// default constructor
Bom::BomXY(int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	
	lcd.fillRect(gridFH.GridF(X),gridFH.GridF(Y),16,16,RGB(255,255,255));
	lcd.fillCircle((gridFH.GridF(X)+7),(gridFH.GridF(Y)+9),5,RGB(0,0,0));
	lcd.drawPixel((gridFH.GridF(X)+11),(gridFH.GridF(Y)+5),RGB(75,86,90));
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+5),RGB(254,100,0));
	lcd.drawPixel((gridFH.GridF(X)+12),(gridFH.GridF(Y)+4),RGB(254,100,0));
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+3),RGB(254,100,0));
	lcd.drawPixel((gridFH.GridF(X)+14),(gridFH.GridF(Y)+4),RGB(254,100,0));
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+4),RGB(255,0,0));
	lcd.drawPixel((gridFH.GridF(X)+6),(gridFH.GridF(Y)+6),RGB(255,255,255));
	lcd.drawPixel((gridFH.GridF(X)+5),(gridFH.GridF(Y)+7),RGB(255,255,255));
} //Bom

Bom::BomExpl(int X, int Y)
{
		MI0283QT9 lcd;  //MI0283QT9 Adapter v1
		GridClass gridFH;
		lcd.fillRect(X, Y, 16, 16, RGB(164,0,0));
		lcd.fillRect((X+1), (Y+1), 14, 14, RGB(214,0,0));
		lcd.fillRect((X+2), (Y+2), 12, 12, RGB(255,80,10));
		lcd.fillRect((X+3), (Y+3), 10, 10, RGB(255,120,50));
		lcd.fillRect((X+4), (Y+4), 8, 8, RGB(255,170,90));
		lcd.fillRect((X+5), (Y+5), 6, 6, RGB(255,255,170));
		lcd.fillRect((X+6), (Y+6), 4, 4, RGB(255,255,255));
				
}//explosion

/*
			lcd.fillRect((X-16), (Y-16), 16, 16, RGB(164,0,0));
			lcd.fillRect(((X+1)-16), ((Y+1)-16), 14, 14, RGB(214,0,0));
			lcd.fillRect(((X+2)-16), ((Y+2)-16), 12, 12, RGB(255,80,10));
			lcd.fillRect(((X+3)-16), ((Y+3)-16), 10, 10, RGB(255,120,50));
			lcd.fillRect(((X+4)-16), ((Y+4)-16), 8, 8, RGB(255,170,90));
			lcd.fillRect(((X+5)-16), ((Y+5)-16), 6, 6, RGB(255,255,170));
			lcd.fillRect(((X+6)-16), ((Y+6)-16), 4, 4, RGB(255,255,255));
*/