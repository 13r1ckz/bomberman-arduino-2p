

#include "Bom.h"

// default constructor
Bom::BomXY(int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	
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

