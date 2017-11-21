#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <Wire.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>

//Declare display !
MI0283QT9 lcd;  //MI0283QT9 Adapter v1



void characterA(int X, int Y) {
	int i,j;
	for(i = 0; i < 10; i++){
		lcd.drawPixel((X + (i+3)),(Y+0),RGB(2,13,199));
	}
	
	lcd.drawPixel(2,1,RGB(2,13,199));
	for(i = 0; i < 10; i++){
		lcd.drawPixel((X+(i+3)),(Y+1),RGB(49,127,236));
	}
	lcd.drawPixel((X+13),(Y+1),RGB(2,13,199));
	
	lcd.drawPixel((X+ 1),(Y+2),RGB(2,13,199));
	for(i = 0; i < 12; i++){
		lcd.drawPixel((X+(i+2)),(Y+2),RGB(49,127,236));
	}
	lcd.drawPixel((X+14),(Y+2),RGB(2,13,199));
	
	lcd.drawPixel((X+1),(Y+3),RGB(2,13,199));
	for(i = 0; i < 12; i++){
		lcd.drawPixel((X+(i+2)),(Y+3),RGB(49,127,236));
	}
	lcd.drawPixel((X+14),(Y+3),RGB(2,13,199));
	
	lcd.drawPixel((X+1),(Y+4),RGB(2,13,199));
	lcd.drawPixel((X+2),(Y+4),RGB(49,127,236));
	for(i = 0; i < 10; i++){
		lcd.drawPixel((X+(i+3)),(Y+4),RGB(2,13,199));
	}
	lcd.drawPixel((X+13),(Y+4),RGB(49,127,236));
	lcd.drawPixel((X+14),(Y+4),RGB(2,13,199));
	
	lcd.drawPixel((X+2),(Y+5),RGB(2,13,199));
	for(i = 0; i < 10; i++){
		lcd.drawPixel((X+(i+3)),(Y+5),RGB(49,127,236));
	}
	lcd.drawPixel((X+13),(Y+5),RGB(2,13,199));
	
	for(i = 0; i < 12; i++){
		lcd.drawPixel((X+(i+2)),(Y+6),RGB(2,13,199));
	}
	
	lcd.drawPixel((X+3),(Y+7),RGB(254,204,154));
	lcd.drawPixel((X+4),(Y+7),RGB(255,255,255));
	lcd.drawPixel((X+5),(Y+7),RGB(0,0,0));
	lcd.drawPixel((X+6),(Y+7),RGB(255,255,255));
	lcd.drawPixel((X+7),(Y+7),RGB(254,204,154));
	lcd.drawPixel((X+8),(Y+7),RGB(254,204,154));
	lcd.drawPixel((X+9),(Y+7),RGB(255,255,255));
	lcd.drawPixel((X+10),(Y+7),RGB(0,0,0));
	lcd.drawPixel((X+11),(Y+7),RGB(255,255,255));
	lcd.drawPixel((X+12),(Y+7),RGB(254,204,154));
	
	lcd.drawPixel((X+0),(Y+8),RGB(254,204,154));
	lcd.drawPixel((X+1),(Y+8),RGB(254,204,154));
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+3)),(Y+8),RGB(254,204,154));
	}
	lcd.drawPixel((X+7),(Y+8),RGB(253,154,102));
	lcd.drawPixel((X+8),(Y+8),RGB(253,154,102));
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+9)),(Y+8),RGB(254,204,154));
	}

	lcd.drawPixel((X+14),(Y+8),RGB(254,204,154));
	lcd.drawPixel((X+15),(Y+8),RGB(254,204,154));
	
	lcd.drawPixel((X+0),(Y+9),RGB(254,204,154));
	lcd.drawPixel((X+1),(Y+9),RGB(254,204,154));
	lcd.drawPixel((X+2),(Y+9),RGB(2,13,199));
	lcd.drawPixel((X+4),(Y+9),RGB(2,13,199));
	for(i = 0; i < 6; i++){
		lcd.drawPixel((X+(i+5)),(Y+9),RGB(49,127,236));
	}
	lcd.drawPixel((X+11),(Y+9),RGB(2,13,199));
	lcd.drawPixel((X+13),(Y+9),RGB(2,13,199));
	lcd.drawPixel((X+14),(Y+9),RGB(254,204,154));
	lcd.drawPixel((X+15),(Y+9),RGB(254,204,154));
	
	lcd.drawPixel((X+1),(Y+10),RGB(2,13,199));
	lcd.drawPixel((X+2),(Y+10),RGB(49,127,236));
	lcd.drawPixel((X+3),(Y+10),RGB(2,13,199));
	for(i = 0; i < 8; i++){
		lcd.drawPixel((X+(i+4)),(Y+10),RGB(49,127,236));
	}
	lcd.drawPixel((X+12),(Y+10),RGB(2,13,199));
	lcd.drawPixel((X+12),(Y+10),RGB(49,127,236));
	lcd.drawPixel((X+12),(Y+10),RGB(2,13,199));

	for(i = 0; i < 3; i++){
		lcd.drawPixel((X+(i+2)),(Y+11),RGB(2,13,199));
	}
	for(i = 0; i < 6; i++){
		lcd.drawPixel((X+(i+5)),(Y+11),RGB(49,127,236));
	}
	for(i = 0; i < 3; i++){
		lcd.drawPixel((X+(i+11)),(Y+11),RGB(2,13,199));
	}
	
	for(i = 0; i < 8; i++){
		lcd.drawPixel((X+(i+4)),(Y+12),RGB(2,13,199));
	}
	
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+3)),(Y+13),RGB(2,13,199));
	}
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+9)),(Y+13),RGB(2,13,199));
	}
	
	for(i = 0; i < 3; i++){
		lcd.drawPixel((X+(i+2)),(Y+14),RGB(0,0,0));
	}
	lcd.drawPixel((X+5),(Y+14),RGB(2,13,199));
	lcd.drawPixel((X+10),(Y+14),RGB(2,13,199));
	for(i = 0; i < 3; i++){
		lcd.drawPixel((X+(i+11)),(Y+14),RGB(0,0,0));
	}
	
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+2)),(Y+15),RGB(0,0,0));
	}
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+10)),(Y+15),RGB(0,0,0));
	}
	
}

void characterB(int X, int Y) {
	int i,j;
	for(i = 0; i < 10; i++){
		lcd.drawPixel((X+(i+3)),(Y+0),RGB(194,0,9));
	}
	
	lcd.drawPixel((X+2),(Y+1),RGB(194,0,9));
	for(i = 0; i < 10; i++){
		lcd.drawPixel((X+(i+3)),(Y+1),RGB(255,1,12));
	}
	lcd.drawPixel((X+13),(Y+1),RGB(194,0,9));
	
	lcd.drawPixel((X+1),(Y+2),RGB(194,0,9));
	for(i = 0; i < 12; i++){
		lcd.drawPixel((X+(i+2)),(X+2),RGB(255,1,12));
	}
	lcd.drawPixel((X+14),(Y+2),RGB(194,0,9));
	
	lcd.drawPixel((X+1),(Y+3),RGB(194,0,9));
	for(i = 0; i < 12; i++){
		lcd.drawPixel((X+(i+2)),(Y+3),RGB(255,1,12));
	}
	lcd.drawPixel((X+14),(Y+3),RGB(194,0,9));
	
	lcd.drawPixel((X+1),(Y+4),RGB(194,0,9));
	lcd.drawPixel((X+2),(X+4),RGB(255,1,12));
	for(i = 0; i < 10; i++){
		lcd.drawPixel((X+(i+3)),(Y+4),RGB(194,0,9));
	}
	lcd.drawPixel((X+13),(Y+4),RGB(255,1,12));
	lcd.drawPixel((X+14),(Y+4),RGB(194,0,9));
	
	lcd.drawPixel((X+2),(Y+5),RGB(194,0,9));
	for(i = 0; i < 10; i++){
		lcd.drawPixel((X+(i+3)),(Y+5),RGB(255,1,12));
	}
	lcd.drawPixel((X+13),(Y+5),RGB(194,0,9));
	
	for(i = 0; i < 12; i++){
		lcd.drawPixel((X+(i+2)),(Y+6),RGB(194,0,9));
	}
	
	lcd.drawPixel((X+3),(Y+7),RGB(254,204,154));
	lcd.drawPixel((X+4),(Y+7),RGB(255,255,255));
	lcd.drawPixel((X+5),(Y+7),RGB(0,0,0));
	lcd.drawPixel((X+6),(Y+7),RGB(255,255,255));
	lcd.drawPixel((X+7),(Y+7),RGB(254,204,154));
	lcd.drawPixel((X+8),(Y+7),RGB(254,204,154));
	lcd.drawPixel((X+9),(Y+7),RGB(255,255,255));
	lcd.drawPixel((X+10),(Y+7),RGB(0,0,0));
	lcd.drawPixel((X+11),(Y+7),RGB(255,255,255));
	lcd.drawPixel((X+12),(Y+7),RGB(254,204,154));
	
	lcd.drawPixel((X+0),(Y+8),RGB(254,204,154));
	lcd.drawPixel((X+1),(Y+8),RGB(254,204,154));
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+3)),(Y+8),RGB(254,204,154));
	}
	lcd.drawPixel((X+7),(Y+8),RGB(253,154,102));
	lcd.drawPixel((X+8),(Y+8),RGB(253,154,102));
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+9)),(Y+8),RGB(254,204,154));
	}
	lcd.drawPixel((X+14),(Y+8),RGB(254,204,154));
	lcd.drawPixel((X+15),(Y+8),RGB(254,204,154));
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	lcd.drawPixel((X+0),(Y+9),RGB(254,204,154));
	lcd.drawPixel((X+1),(Y+9),RGB(254,204,154));
	lcd.drawPixel((X+2),(Y+9),RGB(194,0,9));
	lcd.drawPixel((X+4),(Y+9),RGB(194,0,9));
	for(i = 0; i < 6; i++){
		lcd.drawPixel((X+(i+5)),(Y+9),RGB(255,1,12));
	}
	lcd.drawPixel((X+11),(Y+9),RGB(194,0,9));
	lcd.drawPixel((X+13),(Y+9),RGB(194,0,9));
	lcd.drawPixel((X+14),(Y+9),RGB(254,204,154));
	lcd.drawPixel((X+15),(Y+9),RGB(254,204,154));
	
	lcd.drawPixel((X+1),(Y+10),RGB(194,0,9));
	lcd.drawPixel((X+2),(Y+10),RGB(255,1,12));
	lcd.drawPixel((X+3),(Y+10),RGB(194,0,9));
	for(i = 0; i < 8; i++){
		lcd.drawPixel((X+(i+4)),(Y+10),RGB(255,1,12));
	}
	lcd.drawPixel((X+12),(Y+10),RGB(194,0,9));
	lcd.drawPixel((X+13),(Y+10),RGB(255,1,12));
	lcd.drawPixel((X+14),(Y+10),RGB(194,0,9));
	
	for(i = 0; i < 3; i++){
		lcd.drawPixel((X+(i+2)),(Y+11),RGB(194,0,9));
	}
	for(i = 0; i < 6; i++){
		lcd.drawPixel((X+(i+5)),(Y+11),RGB(255,1,12));
	}
	for(i = 0; i < 3; i++){
		lcd.drawPixel((X+(i+11)),(Y+11),RGB(194,0,9));
	}
	
	for(i = 0; i < 8; i++){
		lcd.drawPixel((X+(i+4)),(Y+12),RGB(194,0,9));
	}
	
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+3)),(Y+13),RGB(194,0,9));
	}
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+9)),(Y+13),RGB(194,0,9));
	}
	
	for(i = 0; i < 3; i++){
		lcd.drawPixel((X+(i+2)),(Y+14),RGB(0,0,0));
	}
	lcd.drawPixel((X+5),(Y+14),RGB(194,0,9));
	lcd.drawPixel((X+10),(Y+14),RGB(194,0,9));
	for(i = 0; i < 3; i++){
		lcd.drawPixel((X+(i+11)),(Y+14),RGB(0,0,0));
	}
	
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+2)),(Y+15),RGB(0,0,0));
	}
	for(i = 0; i < 4; i++){
		lcd.drawPixel((X+(i+10)),(Y+15),RGB(0,0,0));
	}
}

int main(void)
{
	init();
	Serial.begin(9600);
	//	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	uint8_t clear_bg=0x00; //0x80 = dont clear background for fonts (only for DisplayXXX)

	//init display
	lcd.begin();

	//clear screen
	lcd.fillScreen(RGB(255,255,255));
	characterA(224,0);
	characterB(0,0);
	while (1)
	{
	
	}
}
