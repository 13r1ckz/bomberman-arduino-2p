/* 
* Character.cpp
*
* Created: 11/30/2017 11:01:42 AM
* Author: gerjon
*/

#define DARKBLUE 0x78
#define LIGHTBLUE 0x33FD
#define BLACK 0x00
#define WHITE 0xFFFFFFFF
#define SKIN 0xFFFFFE73
#define MOUTH 0xFFFFFCCC
#define DARKRED 0xFFFFC001
#define LIGHTRED 0xFFFFF801


//RGB(2,13,199)

#include "Character.h"

// default constructor
Character::MoveA(int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	int i,j;
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y), gridFH.GridF(X)+12, gridFH.GridF(Y), DARKBLUE);	//Hat
	
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+1, gridFH.GridF(X)+13, gridFH.GridF(Y)+1, DARKBLUE);
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y)+1, gridFH.GridF(X)+12, gridFH.GridF(Y)+1, LIGHTBLUE);
	
	lcd.drawLine(gridFH.GridF(X)+1, gridFH.GridF(Y)+2, gridFH.GridF(X)+14, gridFH.GridF(Y)+2, DARKBLUE);
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+2, gridFH.GridF(X)+13, gridFH.GridF(Y)+2, LIGHTBLUE);
	
	lcd.drawLine(gridFH.GridF(X)+1, gridFH.GridF(Y)+3, (gridFH.GridF(X)+14), gridFH.GridF(Y)+3, DARKBLUE);
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+3, (gridFH.GridF(X)+13), gridFH.GridF(Y)+3, LIGHTBLUE);
	
	lcd.drawLine(gridFH.GridF(X)+1, gridFH.GridF(Y)+4, gridFH.GridF(X)+14, gridFH.GridF(Y)+4, DARKBLUE);
	lcd.drawPixel(gridFH.GridF(X)+2, gridFH.GridF(Y)+4, LIGHTBLUE);
	lcd.drawPixel(gridFH.GridF(X)+13, gridFH.GridF(Y)+4, LIGHTBLUE);
	
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+5, gridFH.GridF(X)+13, gridFH.GridF(Y)+5, DARKBLUE);
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y)+5, gridFH.GridF(X)+12, gridFH.GridF(Y)+5, LIGHTBLUE);
	
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+6, gridFH.GridF(X)+13, gridFH.GridF(Y)+6, DARKBLUE);
		
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y)+7, gridFH.GridF(X)+12, gridFH.GridF(Y)+7, SKIN);	//Face
	lcd.drawLine(gridFH.GridF(X)+4, gridFH.GridF(Y)+7, gridFH.GridF(X)+6, gridFH.GridF(Y)+7, WHITE);
	lcd.drawPixel(gridFH.GridF(X)+5, gridFH.GridF(Y)+7, BLACK);
	lcd.drawLine(gridFH.GridF(X)+9, gridFH.GridF(Y)+7, gridFH.GridF(X)+11, gridFH.GridF(Y)+7, WHITE);
	lcd.drawPixel(gridFH.GridF(X)+10, gridFH.GridF(Y)+7, BLACK);
	
	lcd.drawLine(gridFH.GridF(X), gridFH.GridF(Y)+8, gridFH.GridF(X)+1, gridFH.GridF(Y)+8, SKIN);
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y)+8, gridFH.GridF(X)+12, gridFH.GridF(Y)+8, SKIN);
	lcd.drawLine(gridFH.GridF(X)+7, gridFH.GridF(Y)+8, gridFH.GridF(X)+8, gridFH.GridF(Y)+8, MOUTH);
	lcd.drawLine(gridFH.GridF(X)+14, gridFH.GridF(Y)+8, gridFH.GridF(X)+15, gridFH.GridF(Y)+8, SKIN);
	
	lcd.drawLine(gridFH.GridF(X), gridFH.GridF(Y)+9, gridFH.GridF(X)+1, gridFH.GridF(Y)+9, SKIN);		//Body
	lcd.drawPixel(gridFH.GridF(X)+2, gridFH.GridF(Y)+9, DARKBLUE);
	lcd.drawLine(gridFH.GridF(X)+4, gridFH.GridF(Y)+9, gridFH.GridF(X)+11, gridFH.GridF(Y)+9, DARKBLUE);
	lcd.drawLine(gridFH.GridF(X)+5, gridFH.GridF(Y)+9, gridFH.GridF(X)+10, gridFH.GridF(Y)+9, LIGHTBLUE);
	lcd.drawPixel(gridFH.GridF(X)+13, gridFH.GridF(Y)+9, DARKBLUE);
	lcd.drawLine(gridFH.GridF(X)+14, gridFH.GridF(Y)+9, gridFH.GridF(X)+15, gridFH.GridF(Y)+9, SKIN);
	
	lcd.drawLine(gridFH.GridF(X)+1, gridFH.GridF(Y)+10, gridFH.GridF(X)+14, gridFH.GridF(Y)+10, DARKBLUE);
	lcd.drawPixel(gridFH.GridF(X)+2, gridFH.GridF(Y)+10, LIGHTBLUE);
	lcd.drawLine(gridFH.GridF(X)+4, gridFH.GridF(Y)+10, gridFH.GridF(X)+11, gridFH.GridF(Y)+10, LIGHTBLUE);
	lcd.drawPixel(gridFH.GridF(X)+13, gridFH.GridF(Y)+10, LIGHTBLUE);

	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+11, gridFH.GridF(X)+13, gridFH.GridF(Y)+11, DARKBLUE);
	lcd.drawLine(gridFH.GridF(X)+5, gridFH.GridF(Y)+11, gridFH.GridF(X)+10, gridFH.GridF(Y)+11, LIGHTBLUE);
	
	lcd.drawLine(gridFH.GridF(X)+4, gridFH.GridF(Y)+12, gridFH.GridF(X)+11, gridFH.GridF(Y)+12, DARKBLUE);	//Legs
	
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y)+13, gridFH.GridF(X)+6, gridFH.GridF(Y)+13, DARKBLUE);
	lcd.drawLine(gridFH.GridF(X)+9, gridFH.GridF(Y)+13, gridFH.GridF(X)+12, gridFH.GridF(Y)+13, DARKBLUE);
	
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+14, gridFH.GridF(X)+4, gridFH.GridF(Y)+14, BLACK);		//feet
	lcd.drawPixel((gridFH.GridF(X)+5),(gridFH.GridF(Y)+14), DARKBLUE);
	lcd.drawPixel((gridFH.GridF(X)+10),(gridFH.GridF(Y)+14), DARKBLUE);
	lcd.drawLine(gridFH.GridF(X)+11, gridFH.GridF(Y)+14, gridFH.GridF(X)+13, gridFH.GridF(Y)+14, BLACK);
	
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+15, gridFH.GridF(X)+5, gridFH.GridF(Y)+15, BLACK);
	lcd.drawLine(gridFH.GridF(X)+10, gridFH.GridF(Y)+15, gridFH.GridF(X)+13, gridFH.GridF(Y)+15, BLACK);
} //Character

Character::MoveB(int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	
	int i,j;
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y), gridFH.GridF(X)+12, gridFH.GridF(Y), DARKRED);	//Hat
	
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+1, gridFH.GridF(X)+13, gridFH.GridF(Y)+1, DARKRED);
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y)+1, gridFH.GridF(X)+12, gridFH.GridF(Y)+1, LIGHTRED);
	
	lcd.drawLine(gridFH.GridF(X)+1, gridFH.GridF(Y)+2, gridFH.GridF(X)+14, gridFH.GridF(Y)+2, DARKRED);
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+2, gridFH.GridF(X)+13, gridFH.GridF(Y)+2, LIGHTRED);
	
	lcd.drawLine(gridFH.GridF(X)+1, gridFH.GridF(Y)+3, (gridFH.GridF(X)+14), gridFH.GridF(Y)+3, DARKRED);
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+3, (gridFH.GridF(X)+13), gridFH.GridF(Y)+3, LIGHTRED);
	
	lcd.drawLine(gridFH.GridF(X)+1, gridFH.GridF(Y)+4, gridFH.GridF(X)+14, gridFH.GridF(Y)+4, DARKRED);
	lcd.drawPixel(gridFH.GridF(X)+2, gridFH.GridF(Y)+4, LIGHTRED);
	lcd.drawPixel(gridFH.GridF(X)+13, gridFH.GridF(Y)+4, LIGHTRED);
	
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+5, gridFH.GridF(X)+13, gridFH.GridF(Y)+5, DARKRED);
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y)+5, gridFH.GridF(X)+12, gridFH.GridF(Y)+5, LIGHTRED);
	
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+6, gridFH.GridF(X)+13, gridFH.GridF(Y)+6, DARKRED);
	
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y)+7, gridFH.GridF(X)+12, gridFH.GridF(Y)+7, SKIN);	//Face
	lcd.drawLine(gridFH.GridF(X)+4, gridFH.GridF(Y)+7, gridFH.GridF(X)+6, gridFH.GridF(Y)+7, WHITE);
	lcd.drawPixel(gridFH.GridF(X)+5, gridFH.GridF(Y)+7, BLACK);
	lcd.drawLine(gridFH.GridF(X)+9, gridFH.GridF(Y)+7, gridFH.GridF(X)+11, gridFH.GridF(Y)+7, WHITE);
	lcd.drawPixel(gridFH.GridF(X)+10, gridFH.GridF(Y)+7, BLACK);
	
	lcd.drawLine(gridFH.GridF(X), gridFH.GridF(Y)+8, gridFH.GridF(X)+1, gridFH.GridF(Y)+8, SKIN);
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y)+8, gridFH.GridF(X)+12, gridFH.GridF(Y)+8, SKIN);
	lcd.drawLine(gridFH.GridF(X)+7, gridFH.GridF(Y)+8, gridFH.GridF(X)+8, gridFH.GridF(Y)+8, MOUTH);
	lcd.drawLine(gridFH.GridF(X)+14, gridFH.GridF(Y)+8, gridFH.GridF(X)+15, gridFH.GridF(Y)+8, SKIN);
	
	lcd.drawLine(gridFH.GridF(X), gridFH.GridF(Y)+9, gridFH.GridF(X)+1, gridFH.GridF(Y)+9, SKIN);		//Body
	lcd.drawPixel(gridFH.GridF(X)+2, gridFH.GridF(Y)+9, DARKRED);
	lcd.drawLine(gridFH.GridF(X)+4, gridFH.GridF(Y)+9, gridFH.GridF(X)+11, gridFH.GridF(Y)+9, DARKRED);
	lcd.drawLine(gridFH.GridF(X)+5, gridFH.GridF(Y)+9, gridFH.GridF(X)+10, gridFH.GridF(Y)+9, LIGHTRED);
	lcd.drawPixel(gridFH.GridF(X)+13, gridFH.GridF(Y)+9, DARKRED);
	lcd.drawLine(gridFH.GridF(X)+14, gridFH.GridF(Y)+9, gridFH.GridF(X)+15, gridFH.GridF(Y)+9, SKIN);
	
	lcd.drawLine(gridFH.GridF(X)+1, gridFH.GridF(Y)+10, gridFH.GridF(X)+14, gridFH.GridF(Y)+10, DARKRED);
	lcd.drawPixel(gridFH.GridF(X)+2, gridFH.GridF(Y)+10, LIGHTRED);
	lcd.drawLine(gridFH.GridF(X)+4, gridFH.GridF(Y)+10, gridFH.GridF(X)+11, gridFH.GridF(Y)+10, LIGHTRED);
	lcd.drawPixel(gridFH.GridF(X)+13, gridFH.GridF(Y)+10, LIGHTRED);

	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+11, gridFH.GridF(X)+13, gridFH.GridF(Y)+11, DARKRED);
	lcd.drawLine(gridFH.GridF(X)+5, gridFH.GridF(Y)+11, gridFH.GridF(X)+10, gridFH.GridF(Y)+11, LIGHTRED);
	
	lcd.drawLine(gridFH.GridF(X)+4, gridFH.GridF(Y)+12, gridFH.GridF(X)+11, gridFH.GridF(Y)+12, DARKRED);	//Legs
	
	lcd.drawLine(gridFH.GridF(X)+3, gridFH.GridF(Y)+13, gridFH.GridF(X)+6, gridFH.GridF(Y)+13, DARKRED);
	lcd.drawLine(gridFH.GridF(X)+9, gridFH.GridF(Y)+13, gridFH.GridF(X)+12, gridFH.GridF(Y)+13, DARKRED);
	
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+14, gridFH.GridF(X)+4, gridFH.GridF(Y)+14, BLACK);		//feet
	lcd.drawPixel((gridFH.GridF(X)+5),(gridFH.GridF(Y)+14), DARKRED);
	lcd.drawPixel((gridFH.GridF(X)+10),(gridFH.GridF(Y)+14), DARKRED);
	lcd.drawLine(gridFH.GridF(X)+11, gridFH.GridF(Y)+14, gridFH.GridF(X)+13, gridFH.GridF(Y)+14, BLACK);
	
	lcd.drawLine(gridFH.GridF(X)+2, gridFH.GridF(Y)+15, gridFH.GridF(X)+5, gridFH.GridF(Y)+15, BLACK);
	lcd.drawLine(gridFH.GridF(X)+10, gridFH.GridF(Y)+15, gridFH.GridF(X)+13, gridFH.GridF(Y)+15, BLACK);
} //Character
