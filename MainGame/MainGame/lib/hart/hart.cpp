/* 
* hart.cpp
*
* Created: 12/7/2017 11:26:13 AM
* Author: gerjo
*/


#include "hart.h"

// default constructor
hart::HartS(int L, int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	if(L == 3){
		lcd.drawLine((gridFH.GridF(X)+2), gridFH.GridF(Y), (gridFH.GridF(X)+4), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+8), gridFH.GridF(Y), (gridFH.GridF(X)+10), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+5), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+7), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+2), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+2), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+3), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+3), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+4), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+4), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+5), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+5), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+6), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+6), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+2), (gridFH.GridF(Y)+7), (gridFH.GridF(X)+10), (gridFH.GridF(Y)+7), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+3), (gridFH.GridF(Y)+8), (gridFH.GridF(X)+9), (gridFH.GridF(Y)+8), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+4), (gridFH.GridF(Y)+9), (gridFH.GridF(X)+8), (gridFH.GridF(Y)+9), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+5), (gridFH.GridF(Y)+10), (gridFH.GridF(X)+7), (gridFH.GridF(Y)+10), RGB(255,0,0));
		X++;
		lcd.drawLine((gridFH.GridF(X)+2), gridFH.GridF(Y), (gridFH.GridF(X)+4), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+8), gridFH.GridF(Y), (gridFH.GridF(X)+10), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+5), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+7), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+2), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+2), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+3), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+3), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+4), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+4), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+5), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+5), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+6), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+6), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+2), (gridFH.GridF(Y)+7), (gridFH.GridF(X)+10), (gridFH.GridF(Y)+7), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+3), (gridFH.GridF(Y)+8), (gridFH.GridF(X)+9), (gridFH.GridF(Y)+8), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+4), (gridFH.GridF(Y)+9), (gridFH.GridF(X)+8), (gridFH.GridF(Y)+9), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+5), (gridFH.GridF(Y)+10), (gridFH.GridF(X)+7), (gridFH.GridF(Y)+10), RGB(255,0,0));
		X++;
		lcd.drawLine((gridFH.GridF(X)+2), gridFH.GridF(Y), (gridFH.GridF(X)+4), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+8), gridFH.GridF(Y), (gridFH.GridF(X)+10), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+5), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+7), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+2), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+2), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+3), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+3), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+4), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+4), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+5), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+5), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+6), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+6), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+2), (gridFH.GridF(Y)+7), (gridFH.GridF(X)+10), (gridFH.GridF(Y)+7), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+3), (gridFH.GridF(Y)+8), (gridFH.GridF(X)+9), (gridFH.GridF(Y)+8), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+4), (gridFH.GridF(Y)+9), (gridFH.GridF(X)+8), (gridFH.GridF(Y)+9), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+5), (gridFH.GridF(Y)+10), (gridFH.GridF(X)+7), (gridFH.GridF(Y)+10), RGB(255,0,0));
	}
	else if(L == 2){
		lcd.drawLine((gridFH.GridF(X)+2), gridFH.GridF(Y), (gridFH.GridF(X)+4), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+8), gridFH.GridF(Y), (gridFH.GridF(X)+10), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+5), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+7), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+2), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+2), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+3), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+3), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+4), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+4), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+5), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+5), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+6), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+6), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+2), (gridFH.GridF(Y)+7), (gridFH.GridF(X)+10), (gridFH.GridF(Y)+7), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+3), (gridFH.GridF(Y)+8), (gridFH.GridF(X)+9), (gridFH.GridF(Y)+8), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+4), (gridFH.GridF(Y)+9), (gridFH.GridF(X)+8), (gridFH.GridF(Y)+9), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+5), (gridFH.GridF(Y)+10), (gridFH.GridF(X)+7), (gridFH.GridF(Y)+10), RGB(255,0,0));
		X++;
		lcd.drawLine((gridFH.GridF(X)+2), gridFH.GridF(Y), (gridFH.GridF(X)+4), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+8), gridFH.GridF(Y), (gridFH.GridF(X)+10), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+5), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+7), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+2), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+2), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+3), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+3), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+4), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+4), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+5), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+5), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+6), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+6), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+2), (gridFH.GridF(Y)+7), (gridFH.GridF(X)+10), (gridFH.GridF(Y)+7), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+3), (gridFH.GridF(Y)+8), (gridFH.GridF(X)+9), (gridFH.GridF(Y)+8), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+4), (gridFH.GridF(Y)+9), (gridFH.GridF(X)+8), (gridFH.GridF(Y)+9), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+5), (gridFH.GridF(Y)+10), (gridFH.GridF(X)+7), (gridFH.GridF(Y)+10), RGB(255,0,0));
		X++;
		lcd.fillRect(gridFH.GridF(X), gridFH.GridF(Y), 16, 16, RGB(255,255,255));
	}
	else if(L == 1){
		lcd.drawLine((gridFH.GridF(X)+2), gridFH.GridF(Y), (gridFH.GridF(X)+4), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+8), gridFH.GridF(Y), (gridFH.GridF(X)+10), gridFH.GridF(Y), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+5), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+7), (gridFH.GridF(Y)+1), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+1), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+2), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+2), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+3), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+3), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+4), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+4), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)), (gridFH.GridF(Y)+5), (gridFH.GridF(X)+12), (gridFH.GridF(Y)+5), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+1), (gridFH.GridF(Y)+6), (gridFH.GridF(X)+11), (gridFH.GridF(Y)+6), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+2), (gridFH.GridF(Y)+7), (gridFH.GridF(X)+10), (gridFH.GridF(Y)+7), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+3), (gridFH.GridF(Y)+8), (gridFH.GridF(X)+9), (gridFH.GridF(Y)+8), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+4), (gridFH.GridF(Y)+9), (gridFH.GridF(X)+8), (gridFH.GridF(Y)+9), RGB(255,0,0));
		lcd.drawLine((gridFH.GridF(X)+5), (gridFH.GridF(Y)+10), (gridFH.GridF(X)+7), (gridFH.GridF(Y)+10), RGB(255,0,0));
		X++;
		lcd.fillRect(gridFH.GridF(X), gridFH.GridF(Y), 16, 16, RGB(255,255,255));
		X++;
		lcd.fillRect(gridFH.GridF(X), gridFH.GridF(Y), 16, 16, RGB(255,255,255));
	}
} 