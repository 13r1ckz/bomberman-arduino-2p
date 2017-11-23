#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <Wire.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <ArduinoNunchuk.h>
#include <EEPROM.h>


//Declare display !
MI0283QT9 lcd;  //MI0283QT9 Adapter v1
ArduinoNunchuk nunchuk = ArduinoNunchuk();

void mlevel1() {
	lcd.fillRect(60,15,200,50,0xFFFFFF);
	lcd.drawText(82,30, "Level 1", 0x111111, 0xFFFFFF, 3.5);
}
void mlevel2() {
	lcd.fillRect(60,70,200,50,0xFFFFFF);
	lcd.drawText(82,85, "Level 2", 0x111111, 0xFFFFFF, 3.5);
}
void mlevelRandom() {
	lcd.fillRect(60,125,200,50,0xFFFFFF);
	lcd.drawText(89,140, "Random", 0x111111, 0xFFFFFF, 3.5);
}
void mhighScore() {
	lcd.fillRect(60,180,200,50,0xFFFFFF);
	lcd.drawText(82,195, "High score", 0x111111, 0xFFFFFF, 2);
}
void characterA(int X, int Y) {
	int i,j;
	for(i = 0; i < 10; i++){
		lcd.drawPixel((X + (i+3)),(Y+0),RGB(2,13,199));
	}
	
	lcd.drawPixel((X+2),(Y+1),RGB(2,13,199));
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
		lcd.drawPixel((X+(i+2)),(Y+2),RGB(255,1,12));
	}
	lcd.drawPixel((X+14),(Y+2),RGB(194,0,9));
	
	lcd.drawPixel((X+1),(Y+3),RGB(194,0,9));
	for(i = 0; i < 12; i++){
		lcd.drawPixel((X+(i+2)),(Y+3),RGB(255,1,12));
	}
	lcd.drawPixel((X+14),(Y+3),RGB(194,0,9));
	
	lcd.drawPixel((X+1),(Y+4),RGB(194,0,9));
	lcd.drawPixel((X+2),(Y+4),RGB(255,1,12));
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

int navigateStart() {
	int nunchukY = 1;
	int counter = 5;
	int i = 0;
	
	while(1) {
		//single_sample();
		nunchuk.update();
		if(nunchuk.analogY < 60) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) {
				nunchukY++;
				i++;
			}
			i++;
		}
		
		if(nunchuk.analogY > 200) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) {
				nunchukY--;
				i++;
			}
			i++;
		}
		
		Serial.print(nunchuk.analogY, DEC);
		Serial.print(' ');
		Serial.println(nunchukY, DEC);
		
		if(nunchukY == 1){
			lcd.drawRect(60, 180, 200, 50, RGB(255,255,255));
			lcd.drawRect(61, 181, 198, 48, RGB(255,255,255));
			lcd.drawRect(62, 182, 196, 46, RGB(255,255,255));
			
			lcd.drawRect(60, 70, 200, 50, RGB(255,255,255));
			lcd.drawRect(61, 71, 198, 48, RGB(255,255,255));
			lcd.drawRect(62, 72, 196, 46, RGB(255,255,255));
			
			lcd.drawRect(60, 15, 200, 50, RGB(255,0,0));
			lcd.drawRect(61, 16, 198, 48, RGB(255,0,0));
			lcd.drawRect(62, 17, 196, 46, RGB(255,0,0));
			if (nunchuk.zButton) {
				return 1;
			}
		}
		if(nunchukY == 2){
			lcd.drawRect(60, 15, 200, 50, RGB(255,255,255));
			lcd.drawRect(61, 16, 198, 48, RGB(255,255,255));
			lcd.drawRect(62, 17, 196, 46, RGB(255,255,255));
			
			lcd.drawRect(60, 125, 200, 50, RGB(255,255,255));
			lcd.drawRect(61, 126, 198, 48, RGB(255,255,255));
			lcd.drawRect(62, 127, 196, 46, RGB(255,255,255));
			
			lcd.drawRect(60, 70, 200, 50, RGB(255,0,0));
			lcd.drawRect(61, 71, 198, 48, RGB(255,0,0));
			lcd.drawRect(62, 72, 196, 46, RGB(255,0,0));
			if (nunchuk.zButton) {
				return 2;
			}
		}
		if(nunchukY == 3){
			lcd.drawRect(60, 70, 200, 50, RGB(255,255,255));
			lcd.drawRect(61, 71, 198, 48, RGB(255,255,255));
			lcd.drawRect(62, 72, 196, 46, RGB(255,255,255));
			
			lcd.drawRect(60, 180, 200, 50, RGB(255,255,255));
			lcd.drawRect(61, 181, 198, 48, RGB(255,255,255));
			lcd.drawRect(62, 182, 196, 46, RGB(255,255,255));
			
			lcd.drawRect(60, 125, 200, 50, RGB(255,0,0));
			lcd.drawRect(61, 126, 198, 48, RGB(255,0,0));
			lcd.drawRect(62, 127, 196, 46, RGB(255,0,0));
			
			if (nunchuk.zButton) {
				return 3;
			}
		}
		if(nunchukY == 4){
			lcd.drawRect(60, 125, 200, 50, RGB(255,255,255));
			lcd.drawRect(61, 126, 198, 48, RGB(255,255,255));
			lcd.drawRect(62, 127, 196, 46, RGB(255,255,255));
			
			lcd.drawRect(60, 15, 200, 50, RGB(255,255,255));
			lcd.drawRect(61, 16, 198, 48, RGB(255,255,255));
			lcd.drawRect(62, 17, 196, 46, RGB(255,255,255));
			
			lcd.drawRect(60, 180, 200, 50, RGB(255,0,0));
			lcd.drawRect(61, 181, 198, 48, RGB(255,0,0));
			lcd.drawRect(62, 182, 196, 46, RGB(255,0,0));
			
			if (nunchuk.zButton) {
				return 4;
			}
		}
		if(nunchukY == 5){
			nunchukY = 1;
		}
		if(nunchukY == 0){
			nunchukY = 4;
		}
	}
}

int Startscherm(){
	int level;
	lcd.fillScreen(RGB(0,0,0));
	mlevel1();
	mlevel2();
	mlevelRandom();
	mhighScore();
	lcd.fillRect(0,0,16,16,RGB(255,255,255));
	characterA(0,0);
	lcd.fillRect(304,0,16,16,RGB(255,255,255));
	characterB(304,0);
	level = navigateStart();
	return level;
}

Grid(int X){
	return (X*16);
}

int OuterWall(){
	int i , j;
	int X = 0;
	int Y = 0;
	int outer[][2] = {{1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1},	{7,1}, {8,1}, {9,1}, {10,1}, {11,1}, {12,1}, {13,1}, {14,1}, {15,1},
	{2,2}, {2,15},
	{3,2}, {3,15},
	{4,2}, {4,15},
	{5,2}, {5,15},
	{6,2}, {6,15},
	{7,2}, {7,15},
	{8,2}, {8,15},
	{9,2}, {9,15},
	{10,2}, {10,15},
	{11,2}, {11,15},
	{12,2}, {12,15},
	{13,2}, {13,15},
	{14,2}, {14,15},
	{1,15}, {2,15}, {3,15}, {4,15}, {5,15}, {6,15},	{7,15}, {8,15}, {9,15}, {10,15}, {11,15}, {12,15}, {13,15}, {14,15}, {15,15}};
	
	for(i = 0; i < 15; i++){
		lcd.fillRect(Grid(X),Grid(Y),16,16, 0xFFFFFF);
		lcd.fillRect((Grid(X)+1),(Grid(Y)+1),14,14, 0x000);
		X = X + 1;
	}
	for(i = 0; i < 16; i++){
		lcd.fillRect(0,Grid(Y),16,16, 0xFFFFFF);
		lcd.fillRect(1,(Grid(Y)+1),14,14, 0x000);
		lcd.fillRect(224,Grid(Y),16,16, 0xFFFFFF);
		lcd.fillRect(225,(Grid(Y)+1),14,14, 0x000);
		Y = Y + 1;
	}
	X = 0;
	for(i = 0; i < 15; i++){
		lcd.fillRect(Grid(X),224,16,16, 0xFFFFFF);
		lcd.fillRect((Grid(X)+1),(225),14,14, 0x000);
		X = X + 1;
	}
	return outer;
}

int InnerGrid(){
	int i, j, X, Y, a;
	int inner[][2] = {{3,3}, {5,3}, {7,3}, {9,3}, {11,3}, {13,3},
	{3,5}, {5,5}, {7,5}, {9,5}, {11,5}, {13,5},
	{3,7}, {5,7}, {7,7}, {9,7}, {11,7}, {13,7},
	{3,9}, {5,9}, {7,9}, {9,9}, {11,9}, {13,9},
	{3,11}, {5,11}, {7,11}, {9,11}, {11,11}, {13,11},
	{3,13}, {5,13}, {7,13}, {9,13}, {11,13}, {13,13}};
	X = 2;
	Y = 2;
	for(i = 0; i < 6; i++){
		for(j = 0; j < 6; j++){
			lcd.fillRect((Grid(X)),(Grid(Y)),16,16, 0x000);
			X = X + 2;
			Serial.print("x: ");
			Serial.println(X);
			Serial.println(Grid(X));
		}
		X = 2;
		Y = Y + 2;
		Serial.print("y: ");
		Serial.println(Y);
		Serial.println(Grid(Y));
	}
	return inner;
}

int navigate(){
	int nunchukY = 1;
	int nunchukX = 1;
	int counter = 10;
	int i = 0;
	int gridX, gridY;
	
	while(1) {
		nunchuk.update();
		int XA = Grid(nunchukX);
		int YA = Grid(nunchukY);
		int XB = Grid(13);
		int YB = Grid(13);
		characterA(XA,YA);
		characterB(XB,XB);
		int gridX = 0;
		int gridY = 0;
		
		//omlaag lopen
		if(nunchuk.analogY < 60) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) { 
				nunchukY++;
				int trueX = 0;
				for(int i = 0; i < 6; i++){
					for(int j = 0; j < 6; j++){
						gridX = gridX + 2;
						if(gridX == nunchukX){
							trueX = 1;
						}
					}
					gridX = 2;
					gridY = gridY + 2;
					if((gridY == nunchukY) && (trueX == 1)) {
						nunchukY--;
					}
				}
				if (trueX == 0){
					lcd.fillRect((Grid(nunchukX)),(Grid(nunchukY)-16), 16, 16, RGB(255,255,255)); //wist vorige positie
				}
				i++;
			}
			i++;
		}
		
		//omhoog lopen
		if(nunchuk.analogY > 200) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) { 
				nunchukY--;
				int trueX = 0;
				for(int i = 0; i < 6; i++){
					for(int j = 0; j < 6; j++){
						gridX = gridX + 2;
						if(gridX == nunchukX){
							trueX = 1;
						}
					}
					gridX = 2;
					gridY = gridY + 2;
					if((gridY == nunchukY) && (trueX == 1)) {
						nunchukY++;
					}
				}
				if (trueX == 0){
					lcd.fillRect((Grid(nunchukX)),(Grid(nunchukY)+16), 16, 16, RGB(255,255,255)); //wist vorige positie
				}
				i++;
			}
			i++;
		}
		
		//naar links lopen
		if(nunchuk.analogX < 60) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) {
				nunchukX--; 
				int trueY = 0;
				for(int i = 0; i < 6; i++){
					for(int j = 0; j < 6; j++){
						gridY = gridY + 2;
						if(gridY == nunchukY){
							trueY = 1;
						}
					}
					gridY = 2;
					gridX = gridX + 2;
					if((gridX == nunchukX) && (trueY == 1)) {
						nunchukX++;
					}
				}
				if (trueY == 0){
					lcd.fillRect((Grid(nunchukX)+16),(Grid(nunchukY)), 16, 16, RGB(255,255,255)); //wist vorige positie
				}
				i++;
			}
			i++;
		}
		
		//naar rechts lopen
		if(nunchuk.analogX > 200) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) {
				nunchukX++;
				int trueY = 0;
				for(int i = 0; i < 6; i++){
					for(int j = 0; j < 6; j++){
						gridY = gridY + 2;
						if(gridY == nunchukY){
							trueY = 1;
						}
					}
					gridY = 2;
					gridX = gridX + 2;
					if((gridX == nunchukX) && (trueY == 1)) {
						nunchukX--;
					}
				}
				if (trueY == 0){
					lcd.fillRect((Grid(nunchukX)-16),(Grid(nunchukY)), 16, 16, RGB(255,255,255)); //wist vorige positie
				}
				i++;
			}
			i++;
		}
		
		//outer grid
		if (nunchukX < 1){
			nunchukX = 1;
		}
		if (nunchukX > 13){
			nunchukX = 13;
		}
		if (nunchukY < 1){
			nunchukY = 1;
		}
		if (nunchukY > 13){
			nunchukY = 13;
		}
	}
}

int level1() {
	lcd.fillScreen(RGB(255,255,255));
	OuterWall();
	InnerGrid();
	navigate();
	return;
}

int level2() {
	lcd.fillScreen(RGB(0,255,0));
	OuterWall();
	InnerGrid();
	navigate();
	return;
}

int levelRandom() {
	lcd.fillScreen(RGB(0,0,255));
	OuterWall();
	InnerGrid();
	navigate();
	return;
}

int highScore() {
	lcd.fillScreen(RGB(255,255,0));
	_delay_ms(1000);
	return;
}


int main(void)
{
	int level;
	init();
	Serial.begin(9600);
	//	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	uint8_t clear_bg=0x00; //0x80 = dont clear background for fonts (only for DisplayXXX)

	//init display
	lcd.begin();
	nunchuk.init();
	
	while (1)
	{
		level = Startscherm();
		Serial.println(level, DEC);

		if (level == 1)	{
			level1();
		}
		if (level == 2)	{
			level2();
		}
		if (level == 3)	{
			levelRandom();
		}
		if (level == 4)	{
			highScore();
		}
	}
}