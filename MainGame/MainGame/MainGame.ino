#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <Wire.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <ArduinoNunchuk.h>
#include <EEPROM.h>
#include "lib/Grid/Grid.h"
#include "lib/Wall/Wall.h"
#include "lib/Obstacle/Obstacle.h"
#include "lib/Character/Character.h"
#include "lib/Bom/Bom.h"

//Declare display !
MI0283QT9 lcd;  //MI0283QT9 Adapter v1
ArduinoNunchuk nunchuk = ArduinoNunchuk();

GridClass gridFH;
OuterWall wallOut;
InnerWall wallIn;
Obstacle OB;
Character Characters;
Bom bom;

void init_adc_single_sample()
{
	ADMUX |= (1<<MUX0);		// input analog A1 Arduino
	ADMUX |= (1<<REFS0);	// 5 volt
	ADCSRA |= (1<<ADEN);	// ADC enable
}

void single_sample()
{
	uint8_t bright;
	uint16_t result;
	ADCSRA |= (1<<ADSC);		// Start conversion
	while(ADCSRA & (1<<ADSC)) ;	// Wait
	result = ADC;
	//remap
	bright = map((result >> 2), 0, 255, 0, 10);
	bright = bright * 10;
	lcd.led(bright);
}

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
void woodBox(int X, int Y){
	lcd.fillRect(X, Y, 16, 16, RGB( 150, 111, 51));
	lcd.drawLine((X+1),(Y+1),(X+1),(Y+15), RGB(218,165,32));
	lcd.drawLine((X+3),(Y+1),(X+3),(Y+15), RGB(218,165,32));
	lcd.drawLine((X+5),(Y+1),(X+5),(Y+15), RGB(218,165,32));
	lcd.drawLine((X+7),(Y+1),(X+7),(Y+15), RGB(218,165,32));
	lcd.drawLine((X+9),(Y+1),(X+9),(Y+15), RGB(218,165,32));
	lcd.drawLine((X+11),(Y+1),(X+11),(Y+15), RGB(218,165,32));
	lcd.drawLine((X+13),(Y+1),(X+13u),(Y+15), RGB(218,165,32));
}

int navigateStart() {
	int nunchukY = 1;
	int counter = 5;
	int i = 0;
	
	while(1) {
		single_sample();
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
		
		//Serial.print(nunchuk.analogY, DEC);
		//Serial.print(' ');
		//Serial.println(nunchukY, DEC);
		
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
	Characters.MoveA(0,0);
	lcd.fillRect(304,0,16,16,RGB(255,255,255));
	Characters.MoveB(19,0);
	bom.BomXY(1,0);
	bom.BomXY(18,0);
	level = navigateStart();
	return level;
}


int navigate(){
	int nunchukY = 1;
	int nunchukX = 1;
	int counter = 10;
	int i = 0;
	int q = 0;
	int gridX, gridY;
	int bomb = 0;
	int bomX, bomY;
	int bomcounter = 75;
	
	while(1) {
		single_sample();
		nunchuk.update();
		int XA = gridFH.GridF(nunchukX);
		int YA = gridFH.GridF(nunchukY);
		int XB = gridFH.GridF(13);
		int YB = gridFH.GridF(13);
		Characters.MoveA((XA/16),(YA/16));
		Characters.MoveB((XB/16),(XB/16));
		int gridX = 0;
		int gridY = 0;
		if (bomb==0){
			if (nunchuk.cButton)
			{
				bomX=XA;
				bomY=YA;
				bomb=1;
				q=0;
			}
		}
		if (bomb==1)
		{
			
			bom.BomXY((bomX/16),(bomY/16));
			q++;
		}
		if(q==bomcounter){
			Serial.print("X: ");
			Serial.println(bomX);
			Serial.print("Y: ");
			Serial.println(bomY);
			if(bomX == 16 && bomY == 16){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX+16), bomY);
				bom.BomExpl(bomX, (bomY+16));
			}
			else if(bomX == 16 && bomY == 208){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX+16), bomY);
				bom.BomExpl(bomX, (bomY-16));
			}
			else if(bomX == 208 && bomY == 16){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX-16), bomY);
				bom.BomExpl(bomX, (bomY+16));
			}
			else if(bomX == 208 && bomY == 208){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX-16), bomY);
				bom.BomExpl(bomX, (bomY-16));
			}
			else if(bomX == 16 && bomY == 32 || bomY == 64 || bomY == 96 || bomY == 128 || bomY == 160 || bomY == 162 && bomY == 208){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl(bomX, (bomY+16));
				bom.BomExpl(bomX, (bomY-16));
			}
			else if(bomY == 16 && bomX == 32 || bomX == 64 || bomX == 96 || bomX == 128 || bomX == 160 || bomX == 162 && bomY == 208){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX+16), bomY);
				bom.BomExpl((bomX-16), bomY);
			}
			else if(bomX == 208 && bomY == 32 || bomY == 64 || bomY == 96 || bomY == 128 || bomY == 160 || bomY == 162 && bomY == 208){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl(bomX, (bomY+16));
				bom.BomExpl(bomX, (bomY-16));
			}
			else if(bomY == 208 && bomX == 32 || bomX == 64 || bomX == 96 || bomX == 128 || bomX == 160 || bomX == 162 && bomY == 208){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX+16), bomY);
				bom.BomExpl((bomX-16), bomY);
			}
			else if(bomX == 16){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX+16), bomY);
				bom.BomExpl(bomX, (bomY+16));
				bom.BomExpl(bomX, (bomY-16));
			}
			else if(bomY == 16){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX+16), bomY);
				bom.BomExpl((bomX-16), bomY);
				bom.BomExpl(bomX, (bomY+16));
			}
			else if(bomX == 208){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX-16), bomY);
				bom.BomExpl(bomX, (bomY+16));
				bom.BomExpl(bomX, (bomY-16));
			}
			else if(bomY == 208){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX-16), bomY);
				bom.BomExpl((bomX+16), bomY);
				bom.BomExpl(bomX, (bomY-16));
			}
			else if(bomX == 32 || bomX == 64 || bomX == 96 || bomX == 128 || bomX == 160 || bomX == 162 && bomY == 208){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX-16), bomY);
				bom.BomExpl((bomX+16), bomY);
			}
			else if(bomY == 32 || bomY == 64 || bomY == 96 || bomY == 128 || bomY == 160 || bomY == 162 && bomY == 208){
				bom.BomExpl(bomX, bomY);
				bom.BomExpl(bomX, (bomY-16));
				bom.BomExpl(bomX, (bomY+16));
			}
			else{
				bom.BomExpl(bomX, bomY);
				bom.BomExpl((bomX+16), bomY);
				bom.BomExpl(bomX, (bomY+16));
				bom.BomExpl((bomX-16), bomY);
				bom.BomExpl(bomX, (bomY-16));
			}
			_delay_ms(1000);
			lcd.fillRect(bomX,bomY,16,16,RGB(255,255,255));
			wallIn.InnerWallP();
			q=0;
			bomb = 0;
		}
		Serial.println(q);
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
					lcd.fillRect((gridFH.GridF(nunchukX)),(gridFH.GridF(nunchukY)-16), 16, 16, RGB(255,255,255)); //wist vorige positie
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
					lcd.fillRect((gridFH.GridF(nunchukX)),(gridFH.GridF(nunchukY)+16), 16, 16, RGB(255,255,255)); //wist vorige positie
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
					lcd.fillRect((gridFH.GridF(nunchukX)+16),(gridFH.GridF(nunchukY)), 16, 16, RGB(255,255,255)); //wist vorige positie
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
					lcd.fillRect((gridFH.GridF(nunchukX)-16),(gridFH.GridF(nunchukY)), 16, 16, RGB(255,255,255)); //wist vorige positie
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
	wallOut.OuterWallP();
	wallIn.InnerWallP();
	OB.ObstacleDR(1);
	navigate();
	while(1){}
	//woodBox(Grid(2),Grid(1));
	//woodBox(Grid(6),Grid(3));
	//woodBox(Grid(7),Grid(8));
	//navigate();
	
}

int level2() {
	lcd.fillScreen(RGB(255,255,255));
	wallOut.OuterWallP();
	wallIn.InnerWallP();
	OB.ObstacleDR(2);
	while(1){}
	//lcd.fillScreen(RGB(0,255,0));
	//OuterWall();
	//InnerGrid();
	//navigate();
	//return;
}

int levelRandom() {
	//lcd.fillScreen(RGB(0,0,255));
	//OuterWall.OuterWallP();
	//();
	//navigate();
	//return;
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
	init_adc_single_sample();
	
	while (1)
	{
		level = Startscherm();
		
		//Serial.println(level, DEC);

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