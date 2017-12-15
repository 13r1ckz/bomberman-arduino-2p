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
#include "lib/init/initRW.h"
#include "lib/Navigate/Navigate.h"

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
Navigate nav;
initRW initrw;

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
	int nunchukYStart = 1;
	int time = 5;
	int i = 0;
	char msg;
	
	while(1) {
		single_sample();
		nunchuk.update();
		if(nunchuk.analogY < 60) {
			if(i>time) {
				i=0;
			}
			if(i == 0) {
				nunchukYStart++;
				i++;
			}
			i++;
		}
		
		if(nunchuk.analogY > 200) {
			if(i>time) {
				i=0;
			}
			if(i == 0) {
				nunchukYStart--;
				i++;
			}
			i++;
		}
		
		if (chat.available()){
			msg = chat.read();
			msg = msg - 48;
			if(msg == 1 || msg == 2 || msg == 3 ){
				return msg;
			}
		}
		else{
			if(nunchukYStart == 1){
				nav.navigatestart(1);
				if (nunchuk.zButton) {
					chat.println(1,DEC);
					return 1;
				}
			}
			
			//tekent rode rand om geselecteerde level
			if(nunchukYStart == 2){
				nav.navigatestart(2);
				if (nunchuk.zButton) {
					chat.println(2,DEC);
					return 2;
				}
			}
			if(nunchukYStart == 3){
				nav.navigatestart(3);
				
				if (nunchuk.zButton) {
					chat.println(3,DEC);
					return 3;
				}
			}
			if(nunchukYStart == 4){
				nav.navigatestart(4);
				
				if (nunchuk.zButton) {
					return 4;
				}
			}
			if(nunchukYStart == 5){
				nunchukYStart = 1;
			}
			if(nunchukYStart == 0){
				nunchukYStart = 4;
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
	int counterBomExplosion = 0;
	int gridX, gridY;
	uint8_t bomb = 0;
	uint8_t bomX, bomY;
	int bomExplosion = 75;
	int bomDelete = 50;
	int counterBomDelete = 0;
	int XA, XB, YA, YB;
	
	while(1) {
		single_sample();
		nunchuk.update();
		//
		XA = gridFH.GridF(nunchukX);	// hier move character A
		YA = gridFH.GridF(nunchukY);
		XB = gridFH.GridF(13);			// hier move character B
		YB = gridFH.GridF(13);
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
				counterBomExplosion=0;
				Serial.println(255,BIN);
				chat.println(255,BIN);
			}
		}
		if (bomb==1) {
			bom.BomXY(bomX/16, bomY/16);
			counterBomExplosion++;
		}
		
		if(counterBomExplosion==bomExplosion) {
			bom.BomTrack(bomX, bomY);
			counterBomExplosion=0;
			bomb = 2;
		}
		
		if (bomb == 2) {
			counterBomDelete++;
			if (counterBomDelete == bomDelete) {
				if ((((XA == bomX) || (XA == bomX-16) || (XA == bomX+16)) && (YA == bomY)) || ((XA == bomX) && ((YA == bomY) || (YA == bomY-16) || (YA == bomY+16))))	{ //character A midden in bom
				levensA--;
				}
				if ((((XB == bomX) || (XB == bomX-16) || (XB == bomX+16)) && (YB == bomY)) || ((XB == bomX) && ((YB == bomY) || (YB == bomY-16) || (YB == bomY+16))))	{ //character B midden in bom
					levensB--;
				}
				bom.BomDelete(bomX, bomY);
				bomb = 0;
				counterBomDelete = 0;
			}
		}
		nav.navigate();
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
	initrw.init();
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