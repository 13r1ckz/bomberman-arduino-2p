#include <stdint.h>
#include <Wire.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <ArduinoNunchuk.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include "lib/Grid/Grid.h"
#include "lib/Wall/Wall.h"
#include "lib/Obstacle/Obstacle.h"
#include "lib/Character/Character.h"
#include "lib/Bom/Bom.h"
#include "lib/Data/Data.h"
#include "lib/hart/hart.h"

#define BLACK 0x00
#define WHITE 0xFFFFFFFF
//Declare display !
MI0283QT9 lcd;  //MI0283QT9 Adapter v1
ArduinoNunchuk nunchuk = ArduinoNunchuk();
SoftwareSerial chat(2, 3); // RX, TX

GridClass gridFH;
OuterWall wallOut;
InnerWall wallIn;
Obstacle OB;
Character Characters;
Bom bom;
hart harts;

void init_adc_single_sample()	//init brightness
{
	ADMUX |= (1<<MUX0);		// input analog A1 Arduino
	ADMUX |= (1<<REFS0);	// 5 volt
	ADCSRA |= (1<<ADEN);	// ADC enable
}

void single_sample()	//brightness
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

int navigateStart() { //navigates through start
	int nunchukY = 1;
	int counter = 5;
	int i = 0;
	char msg;
	
	while(1) {
		single_sample();
		nunchuk.update();
		
		if (chat.available()){
				msg = chat.read();
				Serial.print(msg);
				Serial.println(" - send help");		
				msg = msg-48;		
				return msg;
		}
		
		if(nunchuk.analogY < 60) {
			if(i > counter) {
				i = 0;
			}
			if(i == 0) {
				nunchukY++;
				i++;
			}
			i++;
		}
		
		if(nunchuk.analogY > 200) {
			if(i > counter) {
				i = 0;
			}
			if(i == 0) {
				nunchukY--;
				i++;
			}
			i++;
		} else {
			if(nunchukY == 1){
				lcd.drawRect(60, 180, 200, 50, WHITE);
				lcd.drawRect(61, 181, 198, 48, WHITE);
				lcd.drawRect(62, 182, 196, 46, WHITE);
				
				lcd.drawRect(60, 70, 200, 50, WHITE);
				lcd.drawRect(61, 71, 198, 48, WHITE);
				lcd.drawRect(62, 72, 196, 46, WHITE);
				
				lcd.drawRect(60, 15, 200, 50, RGB(255,0,0));
				lcd.drawRect(61, 16, 198, 48, RGB(255,0,0));
				lcd.drawRect(62, 17, 196, 46, RGB(255,0,0));
				if (nunchuk.zButton) {
					chat.println(1,DEC);
					return 1;
				}
			}
			
			//tekent rode rand om geselecteerde level
			if(nunchukY == 2){
				lcd.drawRect(60, 15, 200, 50, WHITE);
				lcd.drawRect(61, 16, 198, 48, WHITE);
				lcd.drawRect(62, 17, 196, 46, WHITE);
				
				lcd.drawRect(60, 125, 200, 50, WHITE);
				lcd.drawRect(61, 126, 198, 48, WHITE);
				lcd.drawRect(62, 127, 196, 46, WHITE);
				
				lcd.drawRect(60, 70, 200, 50, RGB(255,0,0));
				lcd.drawRect(61, 71, 198, 48, RGB(255,0,0));
				lcd.drawRect(62, 72, 196, 46, RGB(255,0,0));
				if (nunchuk.zButton) {
					chat.println(2,DEC);
					return 2;
				}
			}
			if(nunchukY == 3){
				lcd.drawRect(60, 70, 200, 50, WHITE);
				lcd.drawRect(61, 71, 198, 48, WHITE);
				lcd.drawRect(62, 72, 196, 46, WHITE);
				
				lcd.drawRect(60, 180, 200, 50, WHITE);
				lcd.drawRect(61, 181, 198, 48, WHITE);
				lcd.drawRect(62, 182, 196, 46, WHITE);
				
				lcd.drawRect(60, 125, 200, 50, RGB(255,0,0));
				lcd.drawRect(61, 126, 198, 48, RGB(255,0,0));
				lcd.drawRect(62, 127, 196, 46, RGB(255,0,0));
				
				if (nunchuk.zButton) {
					chat.println(3,DEC);
					return 3;
				}
			}
			if(nunchukY == 4){
				lcd.drawRect(60, 125, 200, 50, WHITE);
				lcd.drawRect(61, 126, 198, 48, WHITE);
				lcd.drawRect(62, 127, 196, 46, WHITE);
				
				lcd.drawRect(60, 15, 200, 50, WHITE);
				lcd.drawRect(61, 16, 198, 48, WHITE);
				lcd.drawRect(62, 17, 196, 46, WHITE);
				
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
	return msg;
}

int Startscherm(){
	int level;
	lcd.fillScreen(BLACK);
	
	lcd.fillRect(60, 15, 200, 50, WHITE);		//print knop Level 1
	lcd.drawText(82, 30, "Level 1", 0x111111, WHITE, 3.5);
	
	lcd.fillRect(60, 70, 200, 50, WHITE);		//print knop Level 2
	lcd.drawText(82, 85, "Level 2", 0x111111, WHITE, 3.5);
	
	lcd.fillRect(60, 125, 200, 50, WHITE);		//print knop Random
	lcd.drawText(89, 140, "Random", 0x111111, WHITE, 3.5);
	
	lcd.fillRect(60, 180, 200, 50, WHITE);		//print knop High score
	lcd.drawText(82, 195, "High score", 0x111111, WHITE, 2);
		
	lcd.fillRect(0, 0, 32, 16, WHITE);
	Characters.MoveA(0, 0);
	lcd.fillRect(288, 0, 32, 16, WHITE);
	Characters.MoveB(19, 0);
	bom.BomXY(1, 0);
	bom.BomXY(18, 0);
	level = navigateStart();
	return level;
}

int loseScreen(){
	lcd.fillScreen(BLACK);
	lcd.drawText(38, 50, "You lose", RGB(255,0,0), BLACK, 4);
	return;
}

int winScreen(){
	lcd.fillScreen(BLACK);
	lcd.drawText(50, 50, "You win", RGB(0,255,0), BLACK, 4);
	return;
}

int navigate(){
	uint8_t levensA = 3;
	uint8_t levensB = 3;
	uint8_t nunchukY = 1;	//beginpositie Y
	uint8_t nunchukX = 1;	//beginpositie X
	uint8_t counter = 8;
	int i = 0;
	int q = 0;
	int gridX, gridY;
	uint8_t bomb = 0;
	uint8_t bomX, bomY;
	int bomcounter = 75;
	int bomDelete = 50;
	uint8_t bomMidden = 0;
	uint8_t bomLinks = 0;
	uint8_t bomRechts = 0;
	uint8_t bomOnder = 0;
	uint8_t bomBoven = 0;
	int counterBomDelete = 0;
	int cBomLinks = 0;
	int cBomRechts = 0;
	int cBomOnder = 0;
	int cBomBoven = 0;
	
	while(1) {
		single_sample();
		nunchuk.update();
		int XA = gridFH.GridF(nunchukX);	// hier move character A
		int YA = gridFH.GridF(nunchukY);
		int XB = gridFH.GridF(13);			// hier move character B
		int YB = gridFH.GridF(13);
		Characters.MoveA(XA/16, YA/16);
		Characters.MoveB(XB/16, YB/16);
		int gridX = 0;
		int gridY = 0;
		
		if (chat.available()) {
			Serial.write(chat.read());
		}
		
		harts.HartS(levensA, 16, 2);
		harts.HartS(levensB, 16, 14);
		if (levensA == 0) {
			loseScreen();
			return;
		}
		if (levensB == 0) {
			winScreen();
			return;
		}

		if (bomb==0){				//als er geen bom ligt
			if (nunchuk.zButton) {
				bomX=XA;
				bomY=YA;
				bomb=1;
				q=0;
				Serial.println(255,BIN);
				chat.println(255,BIN);
			}
		}
		if (bomb==1) {
			bom.BomXY(bomX/16, bomY/16);
			q++;
			Serial.println("q++");
		}
		
		if(q==bomcounter) {
				
			bomMidden = 1;
			bom.BomTrack(bomX, bomY);
			q=0;
			bomb = 2;
			Serial.println("q = bomcounter");
			
		}
		
		if (bomb == 2) {
			counterBomDelete++;
			Serial.println(counterBomDelete);
			if (counterBomDelete == bomDelete) {
				Serial.println("BomDelete");
				bom.BomDelete(bomX, bomY);
				bomb = 0;
				counterBomDelete = 0;
			}
		}
		

		/*
		if (bomMidden == 1){		//verwijdert explosie midden
			cBomMidden++;
			if (cBomMidden == (bomcounterDelete+2)){
				lcd.fillRect(bomX, bomY, 16, 16, WHITE);
				cBomMidden = 0;
				bomMidden = 0;
				bomb = 0;
				
				if ((XA == bomX) && (YA == bomY))	{ //character A midden in bom
					levensA--;
				}
				if ((XB == bomX) && (YB == bomY))	{ //character B midden in bom
					levensB--;
				}
			}
		}
		if (bomLinks == 1){			//verwijdert explosie links
			cBomLinks++;
			if (cBomLinks == bomcounterDelete){
				lcd.fillRect(bomX-16, bomY, 16, 16, WHITE);
				cBomLinks = 0;
				bomLinks = 0;
				
				if ((XA == bomX-16) && (YA == bomY))	{ //character A links van bom
				levensA--;
				}
				if ((XB == bomX-16) && (YB == bomY))	{ //character B links van bom
				levensB--;
				}
			}
			
		}
		if (bomRechts == 1){		//verwijdert explosie rechts
			cBomRechts++;
			if (cBomRechts == bomcounterDelete){
				lcd.fillRect(bomX+16, bomY, 16, 16, WHITE);
				cBomRechts = 0;
				bomRechts = 0;
				
				if ((XA == bomX+16) && (YA == bomY))	{ //character A rechts van bom
					levensA--;
				}
				if ((XB == bomX+16) && (YB == bomY))	{ //character B rechts van bom
					levensB--;
				}
			}
		}
		
		if (bomOnder == 1){			//verwijdert explosie onder
			cBomOnder++;
			if (cBomOnder == bomcounterDelete){
				lcd.fillRect(bomX, bomY+16, 16, 16, WHITE);
				cBomOnder = 0;
				bomOnder = 0;
				
				if ((XA == bomX) && (YA == bomY+16))	{ //character A onder bom
					levensA--;
				}
				if ((XB == bomX) && (YB == bomY+16))	{ //character B onder bom
					levensB--;
				}
			}
		}
		
		if (bomBoven == 1){			//verwijdert explosie boven
			cBomBoven++;
			if (cBomBoven == bomcounterDelete){
				lcd.fillRect(bomX, bomY-16, 16, 16, WHITE);
				cBomBoven = 0;
				bomBoven = 0;
				
				if ((XA == bomX) && (YA == bomY-16))	{ //character A boven bom
					levensA--;
				}
				if ((XB == bomX) && (YB == bomY-16))	{ //character B boven bom
					levensB--;
				}
			}
		} */
		
		//omlaag lopen
		if(nunchuk.analogY < 60) {
			if(i > counter) {
				i=0;
			}
			if(i == 0) {		//zorgt dat hij niet te snel loopt
				if (a[YA/16+1][XA/16] == 1)
				{
					nunchukY++;
					chat.println(nunchukX, BIN);
					Serial.print("X: ");
					Serial.println(nunchukX, BIN);
					chat.println(nunchukY, BIN);
					Serial.print("Y: ");
					Serial.println(nunchukY, BIN);
					
					lcd.fillRect(gridFH.GridF(nunchukX), gridFH.GridF(nunchukY)-16, 16, 16, WHITE); //wist vorige positie
				}
			}
			i++;
		}
		
		//omhoog lopen
		if(nunchuk.analogY > 200) {
			if(i > counter) {
				i=0;
			}
			if(i == 0) {	//zorgt dat hij niet te snel loopt
				if (a[YA/16-1][XA/16] == 1)
				{
					nunchukY--;
					chat.println(nunchukX, BIN);
					Serial.print("X: ");
					Serial.println(nunchukX, BIN);
					chat.println(nunchukY, BIN);
					Serial.print("Y: ");
					Serial.println(nunchukY, BIN);
					lcd.fillRect(gridFH.GridF(nunchukX), gridFH.GridF(nunchukY)+16, 16, 16, WHITE); //wist vorige positie
				}
			}
			i++;
		}
		
		//naar links lopen
		if(nunchuk.analogX < 60) {
			if(i > counter) {
				i=0;
			}
			if(i == 0) {	//zorgt dat hij niet te snel loopt
				if (a[YA/16][XA/16-1] == 1)
				{
					nunchukX--;
					chat.println(nunchukX, BIN);
					Serial.print("X: ");
					Serial.println(nunchukX, BIN);
					chat.println(nunchukY, BIN);
					Serial.print("Y: ");
					Serial.println(nunchukY, BIN);
					lcd.fillRect(gridFH.GridF(nunchukX)+16, gridFH.GridF(nunchukY), 16, 16, WHITE); //wist vorige positie
				}
			}
			i++;
		}
		
		//naar rechts lopen
		if(nunchuk.analogX > 200) {
			if(i > counter) {
				i=0;
			}
			if(i == 0) {	//zorgt dat hij niet te snel loopt
				if (a[YA/16][XA/16+1] == 1)
				{
					nunchukX++;
					chat.println(nunchukX, BIN);
					Serial.print("X: ");
					Serial.println(nunchukX, BIN);
					chat.println(nunchukY, BIN);
					Serial.print("Y: ");
					Serial.println(nunchukY, BIN);
					lcd.fillRect(gridFH.GridF(nunchukX)-16, gridFH.GridF(nunchukY), 16, 16, WHITE); //wist vorige positie
				}
			}
			i++;
		}
	}
}

int level1() {
	
	lcd.fillScreen(WHITE);

	wallOut.OuterWallP();
	wallIn.InnerWallP();
	OB.ObstacleDR(1);
	navigate();
	while(1){}
	
}

int level2() {
	lcd.fillScreen(WHITE);
	wallOut.OuterWallP();
	wallIn.InnerWallP();
	OB.ObstacleDR(2);
	navigate();
	while(1){}
}

int levelRandom() {
lcd.fillScreen(WHITE);
wallOut.OuterWallP();
wallIn.InnerWallP();
navigate();
while(1){}
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
	chat.begin(9600);
	uint8_t clear_bg=0x00; //0x80 = dont clear background for fonts (only for DisplayXXX)

	//init display
	lcd.begin();
	nunchuk.init();
	init_adc_single_sample();
	
	while (1)
	{
		
		level = Startscherm();
		//Serial.print("main: level ");
		//Serial.println(level);
		
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
		} else {
			Serial.println("FAIL");
		}
	}
}