/* 
* Character.cpp
*
* Created: 11/30/2017 11:01:42 AM
* Author: gerjo
*/


#include "Character.h"

// default constructor
Character::MoveA(int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	int i,j;
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y), gridFH.GridF(X)+12, gridFH.GridF(Y), RGB(2,13,199));
	
	lcd.drawPixel(gridFH.GridF(X)+2, gridFH.GridF(Y)+1, RGB(2,13,199));
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y)+1, gridFH.GridF(X)+12, gridFH.GridF(Y)+1, RGB(49,127,236));
	lcd.drawPixel(gridFH.GridF(X)+13, gridFH.GridF(Y)+1, RGB(2,13,199));
	
	lcd.drawPixel(gridFH.GridF(X)+1, gridFH.GridF(Y)+2, RGB(2,13,199));
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y) +2, gridFH.GridF(X)+13, gridFH.GridF(Y)+2, RGB(49,127,236));
	lcd.drawPixel(gridFH.GridF(X)+14 , gridFH.GridF(Y)+2, RGB(2,13,199));
	
	lcd.drawPixel(gridFH.GridF(X)+1, gridFH.GridF(Y)+3, RGB(2,13,199));
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y) +3, (gridFH.GridF(X)+13), gridFH.GridF(Y)+3, RGB(49,127,236));
	lcd.drawPixel(gridFH.GridF(X)+14, gridFH.GridF(Y)+3, RGB(2,13,199));
	
	lcd.drawPixel((gridFH.GridF(X)+1),(gridFH.GridF(Y)+4),RGB(2,13,199));
	lcd.drawPixel((gridFH.GridF(X)+2),(gridFH.GridF(Y)+4),RGB(49,127,236));
	for(i = 0; i < 10; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+3)),(gridFH.GridF(Y)+4),RGB(2,13,199));
	}
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+4),RGB(49,127,236));
	lcd.drawPixel((gridFH.GridF(X)+14),(gridFH.GridF(Y)+4),RGB(2,13,199));
	
	lcd.drawPixel((gridFH.GridF(X)+2),(gridFH.GridF(Y)+5),RGB(2,13,199));
	for(i = 0; i < 10; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+3)),(gridFH.GridF(Y)+5),RGB(49,127,236));
	}
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+5),RGB(2,13,199));
	
	for(i = 0; i < 12; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+2)),(gridFH.GridF(Y)+6),RGB(2,13,199));
	}
	
	lcd.drawPixel((gridFH.GridF(X)+3),(gridFH.GridF(Y)+7),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+4),(gridFH.GridF(Y)+7),RGB(255,255,255));
	lcd.drawPixel((gridFH.GridF(X)+5),(gridFH.GridF(Y)+7),RGB(0,0,0));
	lcd.drawPixel((gridFH.GridF(X)+6),(gridFH.GridF(Y)+7),RGB(255,255,255));
	lcd.drawPixel((gridFH.GridF(X)+7),(gridFH.GridF(Y)+7),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+8),(gridFH.GridF(Y)+7),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+9),(gridFH.GridF(Y)+7),RGB(255,255,255));
	lcd.drawPixel((gridFH.GridF(X)+10),(gridFH.GridF(Y)+7),RGB(0,0,0));
	lcd.drawPixel((gridFH.GridF(X)+11),(gridFH.GridF(Y)+7),RGB(255,255,255));
	lcd.drawPixel((gridFH.GridF(X)+12),(gridFH.GridF(Y)+7),RGB(254,204,154));
	
	lcd.drawPixel((gridFH.GridF(X)+0),(gridFH.GridF(Y)+8),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+1),(gridFH.GridF(Y)+8),RGB(254,204,154));
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+3)),(gridFH.GridF(Y)+8),RGB(254,204,154));
	}
	lcd.drawPixel((gridFH.GridF(X)+7),(gridFH.GridF(Y)+8),RGB(253,154,102));
	lcd.drawPixel((gridFH.GridF(X)+8),(gridFH.GridF(Y)+8),RGB(253,154,102));
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+9)),(gridFH.GridF(Y)+8),RGB(254,204,154));
	}

	lcd.drawPixel((gridFH.GridF(X)+14),(gridFH.GridF(Y)+8),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+15),(gridFH.GridF(Y)+8),RGB(254,204,154));
	
	lcd.drawPixel((gridFH.GridF(X)+0),(gridFH.GridF(Y)+9),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+1),(gridFH.GridF(Y)+9),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+2),(gridFH.GridF(Y)+9),RGB(2,13,199));
	lcd.drawPixel((gridFH.GridF(X)+4),(gridFH.GridF(Y)+9),RGB(2,13,199));
	for(i = 0; i < 6; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+5)),(gridFH.GridF(Y)+9),RGB(49,127,236));
	}
	lcd.drawPixel((gridFH.GridF(X)+11),(gridFH.GridF(Y)+9),RGB(2,13,199));
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+9),RGB(2,13,199));
	lcd.drawPixel((gridFH.GridF(X)+14),(gridFH.GridF(Y)+9),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+15),(gridFH.GridF(Y)+9),RGB(254,204,154));
	
	lcd.drawPixel((gridFH.GridF(X)+1),(gridFH.GridF(Y)+10),RGB(2,13,199));
	lcd.drawPixel((gridFH.GridF(X)+2),(gridFH.GridF(Y)+10),RGB(49,127,236));
	lcd.drawPixel((gridFH.GridF(X)+3),(gridFH.GridF(Y)+10),RGB(2,13,199));
	for(i = 0; i < 8; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+4)),(gridFH.GridF(Y)+10),RGB(49,127,236));
	}
	lcd.drawPixel((gridFH.GridF(X)+12),(gridFH.GridF(Y)+10),RGB(2,13,199));
	lcd.drawPixel((gridFH.GridF(X)+12),(gridFH.GridF(Y)+10),RGB(49,127,236));
	lcd.drawPixel((gridFH.GridF(X)+12),(gridFH.GridF(Y)+10),RGB(2,13,199));

	for(i = 0; i < 3; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+2)),(gridFH.GridF(Y)+11),RGB(2,13,199));
	}
	for(i = 0; i < 6; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+5)),(gridFH.GridF(Y)+11),RGB(49,127,236));
	}
	for(i = 0; i < 3; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+11)),(gridFH.GridF(Y)+11),RGB(2,13,199));
	}
	
	for(i = 0; i < 8; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+4)),(gridFH.GridF(Y)+12),RGB(2,13,199));
	}
	
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+3)),(gridFH.GridF(Y)+13),RGB(2,13,199));
	}
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+9)),(gridFH.GridF(Y)+13),RGB(2,13,199));
	}
	
	for(i = 0; i < 3; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+2)),(gridFH.GridF(Y)+14),RGB(0,0,0));
	}
	lcd.drawPixel((gridFH.GridF(X)+5),(gridFH.GridF(Y)+14),RGB(2,13,199));
	lcd.drawPixel((gridFH.GridF(X)+10),(gridFH.GridF(Y)+14),RGB(2,13,199));
	for(i = 0; i < 3; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+11)),(gridFH.GridF(Y)+14),RGB(0,0,0));
	}
	
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+2)),(gridFH.GridF(Y)+15),RGB(0,0,0));
	}
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+10)),(gridFH.GridF(Y)+15),RGB(0,0,0));
	}
} //Character

Character::MoveB(int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	
	int i,j;
	for(i = 0; i < 10; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+3)),(gridFH.GridF(Y)+0),RGB(194,0,9));
	}
	
	lcd.drawPixel((gridFH.GridF(X)+2),(gridFH.GridF(Y)+1),RGB(194,0,9));
	for(i = 0; i < 10; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+3)),(gridFH.GridF(Y)+1),RGB(255,1,12));
	}
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+1),RGB(194,0,9));
	
	lcd.drawPixel((gridFH.GridF(X)+1),(gridFH.GridF(Y)+2),RGB(194,0,9));
	for(i = 0; i < 12; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+2)),(gridFH.GridF(Y)+2),RGB(255,1,12));
	}
	lcd.drawPixel((gridFH.GridF(X)+14),(gridFH.GridF(Y)+2),RGB(194,0,9));
	
	lcd.drawPixel((gridFH.GridF(X)+1),(gridFH.GridF(Y)+3),RGB(194,0,9));
	for(i = 0; i < 12; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+2)),(gridFH.GridF(Y)+3),RGB(255,1,12));
	}
	lcd.drawPixel((gridFH.GridF(X)+14),(gridFH.GridF(Y)+3),RGB(194,0,9));
	
	lcd.drawPixel((gridFH.GridF(X)+1),(gridFH.GridF(Y)+4),RGB(194,0,9));
	lcd.drawPixel((gridFH.GridF(X)+2),(gridFH.GridF(Y)+4),RGB(255,1,12));
	for(i = 0; i < 10; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+3)),(gridFH.GridF(Y)+4),RGB(194,0,9));
	}
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+4),RGB(255,1,12));
	lcd.drawPixel((gridFH.GridF(X)+14),(gridFH.GridF(Y)+4),RGB(194,0,9));
	
	lcd.drawPixel((gridFH.GridF(X)+2),(gridFH.GridF(Y)+5),RGB(194,0,9));
	for(i = 0; i < 10; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+3)),(gridFH.GridF(Y)+5),RGB(255,1,12));
	}
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+5),RGB(194,0,9));
	
	for(i = 0; i < 12; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+2)),(gridFH.GridF(Y)+6),RGB(194,0,9));
	}
	
	lcd.drawPixel((gridFH.GridF(X)+3),(gridFH.GridF(Y)+7),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+4),(gridFH.GridF(Y)+7),RGB(255,255,255));
	lcd.drawPixel((gridFH.GridF(X)+5),(gridFH.GridF(Y)+7),RGB(0,0,0));
	lcd.drawPixel((gridFH.GridF(X)+6),(gridFH.GridF(Y)+7),RGB(255,255,255));
	lcd.drawPixel((gridFH.GridF(X)+7),(gridFH.GridF(Y)+7),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+8),(gridFH.GridF(Y)+7),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+9),(gridFH.GridF(Y)+7),RGB(255,255,255));
	lcd.drawPixel((gridFH.GridF(X)+10),(gridFH.GridF(Y)+7),RGB(0,0,0));
	lcd.drawPixel((gridFH.GridF(X)+11),(gridFH.GridF(Y)+7),RGB(255,255,255));
	lcd.drawPixel((gridFH.GridF(X)+12),(gridFH.GridF(Y)+7),RGB(254,204,154));
	
	lcd.drawPixel((gridFH.GridF(X)+0),(gridFH.GridF(Y)+8),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+1),(gridFH.GridF(Y)+8),RGB(254,204,154));
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+3)),(gridFH.GridF(Y)+8),RGB(254,204,154));
	}
	lcd.drawPixel((gridFH.GridF(X)+7),(gridFH.GridF(Y)+8),RGB(253,154,102));
	lcd.drawPixel((gridFH.GridF(X)+8),(gridFH.GridF(Y)+8),RGB(253,154,102));
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+9)),(gridFH.GridF(Y)+8),RGB(254,204,154));
	}
	lcd.drawPixel((gridFH.GridF(X)+14),(gridFH.GridF(Y)+8),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+15),(gridFH.GridF(Y)+8),RGB(254,204,154));
	
	lcd.drawPixel((gridFH.GridF(X)+0),(gridFH.GridF(Y)+9),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+1),(gridFH.GridF(Y)+9),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+2),(gridFH.GridF(Y)+9),RGB(194,0,9));
	lcd.drawPixel((gridFH.GridF(X)+4),(gridFH.GridF(Y)+9),RGB(194,0,9));
	for(i = 0; i < 6; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+5)),(gridFH.GridF(Y)+9),RGB(255,1,12));
	}
	lcd.drawPixel((gridFH.GridF(X)+11),(gridFH.GridF(Y)+9),RGB(194,0,9));
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+9),RGB(194,0,9));
	lcd.drawPixel((gridFH.GridF(X)+14),(gridFH.GridF(Y)+9),RGB(254,204,154));
	lcd.drawPixel((gridFH.GridF(X)+15),(gridFH.GridF(Y)+9),RGB(254,204,154));
	
	lcd.drawPixel((gridFH.GridF(X)+1),(gridFH.GridF(Y)+10),RGB(194,0,9));
	lcd.drawPixel((gridFH.GridF(X)+2),(gridFH.GridF(Y)+10),RGB(255,1,12));
	lcd.drawPixel((gridFH.GridF(X)+3),(gridFH.GridF(Y)+10),RGB(194,0,9));
	for(i = 0; i < 8; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+4)),(gridFH.GridF(Y)+10),RGB(255,1,12));
	}
	lcd.drawPixel((gridFH.GridF(X)+12),(gridFH.GridF(Y)+10),RGB(194,0,9));
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+10),RGB(255,1,12));
	lcd.drawPixel((gridFH.GridF(X)+14),(gridFH.GridF(Y)+10),RGB(194,0,9));
	
	for(i = 0; i < 3; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+2)),(gridFH.GridF(Y)+11),RGB(194,0,9));
	}
	for(i = 0; i < 6; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+5)),(gridFH.GridF(Y)+11),RGB(255,1,12));
	}
	for(i = 0; i < 3; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+11)),(gridFH.GridF(Y)+11),RGB(194,0,9));
	}
	
	for(i = 0; i < 8; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+4)),(gridFH.GridF(Y)+12),RGB(194,0,9));
	}
	
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+3)),(gridFH.GridF(Y)+13),RGB(194,0,9));
	}
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+9)),(gridFH.GridF(Y)+13),RGB(194,0,9));
	}
	
	for(i = 0; i < 3; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+2)),(gridFH.GridF(Y)+14),RGB(0,0,0));
	}
	lcd.drawPixel((gridFH.GridF(X)+5),(gridFH.GridF(Y)+14),RGB(194,0,9));
	lcd.drawPixel((gridFH.GridF(X)+10),(gridFH.GridF(Y)+14),RGB(194,0,9));
	for(i = 0; i < 3; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+11)),(gridFH.GridF(Y)+14),RGB(0,0,0));
	}
	
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+2)),(gridFH.GridF(Y)+15),RGB(0,0,0));
	}
	for(i = 0; i < 4; i++){
		lcd.drawPixel((gridFH.GridF(X)+(i+10)),(gridFH.GridF(Y)+15),RGB(0,0,0));
	}	
} //Character
