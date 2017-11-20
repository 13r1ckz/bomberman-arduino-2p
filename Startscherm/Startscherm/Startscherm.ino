#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <Wire.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>

//Declare display !
MI0283QT9 lcd;  //MI0283QT9 Adapter v1

void level1() {
	lcd.fillRect(60,15,200,50,0xFFFFFF);
	lcd.drawText(82,30, "Level 1", 0x111111, 0xFFFFFF, 3.5);
}
void level2() {
	lcd.fillRect(60,70,200,50,0xFFFFFF);
	lcd.drawText(82,85, "Level 2", 0x111111, 0xFFFFFF, 3.5);
}
void levelRandom() {
	lcd.fillRect(60,125,200,50,0xFFFFFF);
	lcd.drawText(89,140, "Random", 0x111111, 0xFFFFFF, 3.5);
}
void highScore() {
	lcd.fillRect(60,180,200,50,0xFFFFFF);
	lcd.drawText(82,195, "High score", 0x111111, 0xFFFFFF, 2);
}
void characterA(int X, int Y) {
	int i,j;
	for(i = 0; i < 10; i++){
	lcd.drawPixel((i+3),0,RGB(2,13,199));
	}
	
	lcd.drawPixel(2,1,RGB(2,13,199));
	for(i = 0; i < 10; i++){
	lcd.drawPixel((i+3),1,RGB(49,127,236));
	}
	lcd.drawPixel(13,1,RGB(2,13,199));
	
	lcd.drawPixel(1,2,RGB(2,13,199));
	for(i = 0; i < 12; i++){
	lcd.drawPixel((i+2),2,RGB(49,127,236));
	}
	lcd.drawPixel(14,2,RGB(2,13,199));
	
	lcd.drawPixel(1,3,RGB(2,13,199));
	for(i = 0; i < 12; i++){
		lcd.drawPixel((i+2),3,RGB(49,127,236));
	}
	lcd.drawPixel(14,3,RGB(2,13,199));
	
	lcd.drawPixel(1,4,RGB(2,13,199));
	lcd.drawPixel(2,4,RGB(49,127,236));
	for(i = 0; i < 10; i++){
	lcd.drawPixel((i+3),4,RGB(2,13,199));
	}
	lcd.drawPixel(13,4,RGB(49,127,236));
	lcd.drawPixel(14,4,RGB(2,13,199));
	
	lcd.drawPixel(2,5,RGB(2,13,199));
	for(i = 0; i < 10; i++){
	lcd.drawPixel((i+3),5,RGB(49,127,236));
	}
	lcd.drawPixel(13,5,RGB(2,13,199));
	
	for(i = 0; i < 12; i++){
	lcd.drawPixel((i+2),6,RGB(2,13,199));
	}
	
	lcd.drawPixel(3,7,RGB(254,204,154));
	lcd.drawPixel(4,7,RGB(255,255,255));
	lcd.drawPixel(5,7,RGB(0,0,0));
	lcd.drawPixel(6,7,RGB(255,255,255));
	lcd.drawPixel(7,7,RGB(254,204,154));
	lcd.drawPixel(8,7,RGB(254,204,154));
	lcd.drawPixel(9,7,RGB(255,255,255));
	lcd.drawPixel(10,7,RGB(0,0,0));
	lcd.drawPixel(11,7,RGB(255,255,255));
	lcd.drawPixel(12,7,RGB(254,204,154));
	
	lcd.drawPixel(0,8,RGB(254,204,154));
	lcd.drawPixel(1,8,RGB(254,204,154));
	for(i = 0; i < 4; i++){
	lcd.drawPixel((i+3),8,RGB(254,204,154));
	}
	lcd.drawPixel(7,8,RGB(253,154,102));
	lcd.drawPixel(8,8,RGB(253,154,102));
	for(i = 0; i < 4; i++){
		lcd.drawPixel((i+9),8,RGB(254,204,154));
	}
	lcd.drawPixel(14,8,RGB(254,204,154));
	lcd.drawPixel(15,8,RGB(254,204,154));
	
	lcd.drawPixel(0,9,RGB(254,204,154));
	lcd.drawPixel(1,9,RGB(254,204,154));
	lcd.drawPixel(2,9,RGB(2,13,199));
	lcd.drawPixel(4,9,RGB(2,13,199));
	for(i = 0; i < 6; i++){
		lcd.drawPixel((i+5),9,RGB(49,127,236));
	}
	lcd.drawPixel(11,9,RGB(2,13,199));
	lcd.drawPixel(13,9,RGB(2,13,199));
	lcd.drawPixel(14,9,RGB(254,204,154));
	lcd.drawPixel(15,9,RGB(254,204,154));
	
	lcd.drawPixel(1,10,RGB(2,13,199));
	lcd.drawPixel(2,10,RGB(49,127,236));
	lcd.drawPixel(3,10,RGB(2,13,199));
	for(i = 0; i < 8; i++){
	lcd.drawPixel((i+4),10,RGB(49,127,236));
	}
	lcd.drawPixel(12,10,RGB(2,13,199));
	lcd.drawPixel(13,10,RGB(49,127,236));
	lcd.drawPixel(14,10,RGB(2,13,199));
	
	for(i = 0; i < 3; i++){
	lcd.drawPixel((i+2),11,RGB(2,13,199));
	}
	for(i = 0; i < 6; i++){
	lcd.drawPixel((i+5),11,RGB(49,127,236));
	}
	for(i = 0; i < 3; i++){
		lcd.drawPixel((i+11),11,RGB(2,13,199));
	}
	
	for(i = 0; i < 8; i++){
		lcd.drawPixel((i+4),12,RGB(2,13,199));
	}
	
	for(i = 0; i < 4; i++){
		lcd.drawPixel((i+3),13,RGB(2,13,199));
	}
	for(i = 0; i < 4; i++){
		lcd.drawPixel((i+9),13,RGB(2,13,199));
	}
	
	for(i = 0; i < 3; i++){
		lcd.drawPixel((i+2),14,RGB(0,0,0));
	}
	lcd.drawPixel(5,14,RGB(2,13,199));
	lcd.drawPixel(10,14,RGB(2,13,199));
	for(i = 0; i < 3; i++){
		lcd.drawPixel((i+11),14,RGB(0,0,0));
	}
	
	for(i = 0; i < 4; i++){
		lcd.drawPixel((i+2),15,RGB(0,0,0));
	}
	for(i = 0; i < 4; i++){
		lcd.drawPixel((i+10),15,RGB(0,0,0));
	}
	
}

int Startscherm(){
	lcd.fillScreen(RGB(0,0,0));
	level1();
	level2();
	levelRandom();
	highScore();
	lcd.fillRect(0,0,16,16,RGB(255,255,255));
	characterA(0,0);
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
	Startscherm();
	while (1)
	{
		
	}
}