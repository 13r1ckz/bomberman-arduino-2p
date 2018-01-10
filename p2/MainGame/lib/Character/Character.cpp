#define DARKBLUE 0x78
#define LIGHTBLUE 0x33FD
#define BLACK 0x00
#define WHITE 0xFFFFFFFF
#define SKIN 0xFFFFFE73
#define MOUTH 0xFFFFFCCC
#define DARKRED 0xFFFFC001
#define LIGHTRED 0xFFFFF801


#include "Character.h"

/*
Met deze functie wordt het blauwe karakter getekend
*/
Character::MoveBlue(int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	int i,j;
	lcd.drawLine((X+3), Y, (X+12), Y, DARKBLUE);	//Hat
	
	lcd.drawLine((X+2), (Y+1), (X+13), (Y+1), DARKBLUE);
	lcd.drawLine((X+3), (Y+1), (X+12), (Y+1), LIGHTBLUE);
	
	lcd.drawLine((X+1), (Y+2), (X+14), (Y+2), DARKBLUE);
	lcd.drawLine((X+2), (Y+2), (X+13), (Y+2), LIGHTBLUE);
	
	lcd.drawLine((X+1), (Y+3), (X+14), (Y+3), DARKBLUE);
	lcd.drawLine((X+2), (Y+3), (X+13), (Y+3), LIGHTBLUE);
	
	lcd.drawLine((X+1), (Y+4), (X+14), (Y+4), DARKBLUE);
	lcd.drawPixel((X+2), (Y+4), LIGHTBLUE);
	lcd.drawPixel((X+13), (Y+4), LIGHTBLUE);
	
	lcd.drawLine((X+2), (Y+5), (X+13), (Y+5), DARKBLUE);
	lcd.drawLine((X+3), (Y+5), (X+12), (Y+5), LIGHTBLUE);
	
	lcd.drawLine((X+2), (Y+6), (X+13), (Y+6), DARKBLUE);
	
	lcd.drawLine((X+3), (Y+7), (X+12), (Y+7), SKIN);	//Face
	lcd.drawLine((X+4), (Y+7), (X+6), (Y+7), WHITE);
	lcd.drawPixel((X+5), (Y+7), BLACK);
	lcd.drawLine((X+9), (Y+7), (X+11), (Y+7), WHITE);
	lcd.drawPixel((X+10), (Y+7), BLACK);
	
	lcd.drawLine(X, (Y+8), (X+1), (Y+8), SKIN);
	lcd.drawLine((X+3), (Y+8), (X+12), (Y+8), SKIN);
	lcd.drawLine((X+7), (Y+8), (X+8), (Y+8), MOUTH);
	lcd.drawLine((X+14), (Y+8), (X+15), (Y+8), SKIN);
	
	lcd.drawLine(X, (Y+9), (X+1), (Y+9), SKIN);		//Body
	lcd.drawPixel((X+2), (Y+9), DARKBLUE);
	lcd.drawLine((X+4), (Y+9), (X+11), (Y+9), DARKBLUE);
	lcd.drawLine((X+5), (Y+9), (X+10), (Y+9), LIGHTBLUE);
	lcd.drawPixel((X+13), (Y+9), DARKBLUE);
	lcd.drawLine((X+14), (Y+9), (X+15), (Y+9), SKIN);
	
	lcd.drawLine((X+1), (Y+10), (X+14), (Y+10), DARKBLUE);
	lcd.drawPixel((X+2), (Y+10), LIGHTBLUE);
	lcd.drawLine((X+4), (Y+10), (X+11), (Y+10), LIGHTBLUE);
	lcd.drawPixel((X+13), (Y+10), LIGHTBLUE);

	lcd.drawLine((X+2), (Y+11), (X+13), (Y+11), DARKBLUE);
	lcd.drawLine((X+5), (Y+11), (X+10), (Y+11), LIGHTBLUE);
	
	lcd.drawLine((X+4), (Y+12), (X+11), (Y+12), DARKBLUE);	//Legs
	
	lcd.drawLine((X+3), (Y+13), (X+6), (Y+13), DARKBLUE);
	lcd.drawLine((X+9), (Y+13), (X+12), (Y+13), DARKBLUE);
	
	lcd.drawLine((X+2), (Y+14), (X+4), (Y+14), BLACK);		//feet
	lcd.drawPixel((X+5),(Y+14), DARKBLUE);
	lcd.drawPixel((X+10),(Y+14), DARKBLUE);
	lcd.drawLine((X+11), (Y+14), (X+13), (Y+14), BLACK);
	
	lcd.drawLine((X+2), (Y+15), (X+5), (Y+15), BLACK);
	lcd.drawLine((X+10), (Y+15), (X+13), (Y+15), BLACK);
} //Character
/*
Met deze functie wordt het blauwe karakter getekend
*/
Character::MoveRed(int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	int i,j;
	lcd.drawLine((X+3), Y, (X+12), Y, DARKRED);	//Hat
	
	lcd.drawLine((X+2), (Y+1), (X+13), (Y+1), DARKRED);
	lcd.drawLine((X+3), (Y+1), (X+12), (Y+1), LIGHTRED);
	
	lcd.drawLine((X+1), (Y+2), (X+14), (Y+2), DARKRED);
	lcd.drawLine((X+2), (Y+2), (X+13), (Y+2), LIGHTRED);
	
	lcd.drawLine((X+1), (Y+3), (X+14), (Y+3), DARKRED);
	lcd.drawLine((X+2), (Y+3), (X+13), (Y+3), LIGHTRED);
	
	lcd.drawLine((X+1), (Y+4), (X+14), (Y+4), DARKRED);
	lcd.drawPixel((X+2), (Y+4), LIGHTRED);
	lcd.drawPixel((X+13), (Y+4), LIGHTRED);
	
	lcd.drawLine((X+2), (Y+5), (X+13), (Y+5), DARKRED);
	lcd.drawLine((X+3), (Y+5), (X+12), (Y+5), LIGHTRED);
	
	lcd.drawLine((X+2), (Y+6), (X+13), (Y+6), DARKRED);
	
	lcd.drawLine((X+3), (Y+7), (X+12), (Y+7), SKIN);	//Face
	lcd.drawLine((X+4), (Y+7), (X+6), (Y+7), WHITE);
	lcd.drawPixel((X+5), (Y+7), BLACK);
	lcd.drawLine((X+9), (Y+7), (X+11), (Y+7), WHITE);
	lcd.drawPixel((X+10), (Y+7), BLACK);
	
	lcd.drawLine(X, (Y+8), (X+1), (Y+8), SKIN);
	lcd.drawLine((X+3), (Y+8), (X+12), (Y+8), SKIN);
	lcd.drawLine((X+7), (Y+8), (X+8), (Y+8), MOUTH);
	lcd.drawLine((X+14), (Y+8), (X+15), (Y+8), SKIN);
	
	lcd.drawLine(X, (Y+9), (X+1), (Y+9), SKIN);		//Body
	lcd.drawPixel((X+2), (Y+9), DARKRED);
	lcd.drawLine((X+4), (Y+9), (X+11), (Y+9), DARKRED);
	lcd.drawLine((X+5), (Y+9), (X+10), (Y+9), LIGHTRED);
	lcd.drawPixel((X+13), (Y+9), DARKRED);
	lcd.drawLine((X+14), (Y+9), (X+15), (Y+9), SKIN);
	
	lcd.drawLine((X+1), (Y+10), (X+14), (Y+10), DARKRED);
	lcd.drawPixel((X+2), (Y+10), LIGHTRED);
	lcd.drawLine((X+4), (Y+10), (X+11), (Y+10), LIGHTRED);
	lcd.drawPixel((X+13), (Y+10), LIGHTRED);

	lcd.drawLine((X+2), (Y+11), (X+13), (Y+11), DARKRED);
	lcd.drawLine((X+5), (Y+11), (X+10), (Y+11), LIGHTRED);
	
	lcd.drawLine((X+4), (Y+12), (X+11), (Y+12), DARKRED);	//Legs
	
	lcd.drawLine((X+3), (Y+13), (X+6), (Y+13), DARKRED);
	lcd.drawLine((X+9), (Y+13), (X+12), (Y+13), DARKRED);
	
	lcd.drawLine((X+2), (Y+14), (X+4), (Y+14), BLACK);		//feet
	lcd.drawPixel((X+5),(Y+14), DARKRED);
	lcd.drawPixel((X+10),(Y+14), DARKRED);
	lcd.drawLine((X+11), (Y+14), (X+13), (Y+14), BLACK);
	
	lcd.drawLine((X+2), (Y+15), (X+5), (Y+15), BLACK);
	lcd.drawLine((X+10), (Y+15), (X+13), (Y+15), BLACK);
} //Character