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
#include "lib/Data/Data.h"
#include "lib/hart/hart.h"
#include "lib/init/initRW.h"
#include "lib/Navigate/Navigate.h"
#include "lib/IRcom/IRcom.h"
#define BLACK 0x00
#define WHITE 0xFFFFFFFF

//Declare display !
MI0283QT9 lcd;  //MI0283QT9 Adapter v1
ArduinoNunchuk nunchuk = ArduinoNunchuk();
GridClass gridFH;
OuterWall wallOut;
InnerWall wallIn;
Obstacle OB;
Character Characters;
Bom bom;
hart harts;
Navigate nav;
initRW initrw;
IRcom ir;

uint8_t loopX = 1;
uint8_t loopY = 1;
uint8_t lopen = 0;
ISR(TIMER2_COMPB_vect){
}

ISR(TIMER1_OVF_vect) {    //macro met interrupt vector
	ir.setTellerVerzender(ir.getTellerVerzender() + 1);
	ir.setTellerOntvanger(ir.getTellerOntvanger() + 1);
}

ISR(INT0_vect){
	//Serial.println("i");
	ir.verschil = ir.getTellerOntvanger() - ir.tempteller;
	
	if(ir.startbit == 0){
		if(ir.verschil >= 40){
			ir.startbit = 1;
			ir.ontvangeraantal++;
			//Serial.println("Startbit");
		}
		} else if (ir.startbit == 1){
		if(ir.verschil >= 40){
			ir.startbit = 0;
			ir.setTellerOntvanger(0);
			ir.tempteller = 0;
			ir.ontvangeraantal++;
			} else if(ir.verschil >= 30 && ir.verschil <40){
			Serial.println("1");
			ir.ontvangenbericht |=(1<<ir.bitteller);
			ir.bitteller--;
			ir.ontvangeraantal++;
			} else if(ir.verschil >= 20 && ir.verschil <30){
			Serial.println("0");
			ir.ontvangenbericht &=~(1<<ir.bitteller);
			ir.bitteller--;
			ir.ontvangeraantal++;
		}
	}
	
	if(ir.ontvangeraantal % 10 == 0){
		if(ir.bitteller == -1){
			ir.bitteller = 7;
			ir.letter = ir. ontvangenbericht;
			Serial.println(ir.letter);
			ir.ontvangenbericht = 0x00;
			}else{
			ir.bitteller =7;
			ir.ontvangenbericht = 0x00;
		}
	}
	ir.tempteller = ir.getTellerOntvanger();
}

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
	
	nunchuk.update();
	
	while(nunchuk.zButton == 0) {
		
		nunchuk.update();
		single_sample();
		
		if(nunchuk.analogY < 60) {
			if(i>counter) {
				i=0;
			}
			if(i == 0 && nunchukY < 4) {
				nunchukY++;
				i++;
			}
			i++;
		}
		
		if(nunchuk.analogY > 200) {
			if(i>counter) {
				i=0;
			}
			if(i == 0 && nunchukY > 1) {
				nunchukY--;
				i++;
			}
			i++;
		}
		
		
		if (Serial.available()){
			msg = Serial.read();
			
			msg = msg - 48;
			if(msg >= 1 || msg <= 5){
				return msg;
			}
		}
		
		else{
			if(nunchukY == 1){
				nav.navigatestart(1);

			}
			if(nunchukY == 2){
				nav.navigatestart(2); //tekent rode rand om geselecteerde level

			}
			if(nunchukY == 3){
				nav.navigatestart(3);
				
			}
			if(nunchukY == 4){
				nav.navigatestart(4);
				
			}
		}
	}

	Serial.println(nunchukY,DEC);
	return nunchukY;
}

int Startscherm(){
	//int level;
	lcd.fillScreen(RGB(0,0,0));
	
	lcd.fillRect(60,15,200,50,0xFFFFFF);		//print knop Level 1
	lcd.drawText(82,30, "Level 1", 0x111111, 0xFFFFFF, 3.5);
	
	lcd.fillRect(60,70,200,50,0xFFFFFF);		//print knop Level 2
	lcd.drawText(82,85, "Level 2", 0x111111, 0xFFFFFF, 3.5);
	
	lcd.fillRect(60,125,200,50,0xFFFFFF);		//print knop Random
	lcd.drawText(89,140, "Random", 0x111111, 0xFFFFFF, 3.5);
	
	lcd.fillRect(60,180,200,50,0xFFFFFF);		//print knop High score
	lcd.drawText(82,195, "High score", 0x111111, 0xFFFFFF, 2);
	
	lcd.fillRect(0,0,32,16,RGB(255,255,255));
	Characters.MoveBlue(0,0);
	lcd.fillRect(288,0,32,16,RGB(255,255,255));
	Characters.MoveRed(19,0);
	bom.BomXY(1,0);
	bom.BomXY(18,0);

	return;
}

int resetGrid(){
	for (int i = 1; i < 14; i++) {		//leegt veld
		for (int j = 1; j < 14; j++) {
			a[i][j] = 1;
		}
	}
	for (int i = 2; i < 13; i+=2) {		//zet binnenmuren
		for (int j = 2; j < 13; j+=2) {
			a[i][j] = 2;
		}
	}
}

int loseScreen(){
	lcd.fillScreen(BLACK);
	lcd.drawText(38, 50, "You lose", RGB(255,0,0), BLACK, 4);
	lcd.drawText(80, 130, "Punten: ", WHITE, BLACK, 2);
	lcd.drawInteger(200, 130, points, DEC, WHITE, BLACK, 2 | 0x00);
	levensA = 3;
	levensB = 3;
	points = 0;
	
	
	while(!nunchuk.zButton) {
		nunchuk.update();
		delay(1);
	}
	
	return;
}

int winScreen(){
	lcd.fillScreen(BLACK);
	lcd.drawText(50, 50, "You win", RGB(0,255,0), BLACK, 4);
	lcd.drawText(80, 130, "Punten: ", WHITE, BLACK, 2);
	lcd.drawInteger(200, 130, points, DEC, WHITE, BLACK, 2 | 0x00);
	levensA = 3;
	levensB = 3;
	points = 0;
	
	
	while(!nunchuk.zButton) {
		nunchuk.update();
		delay(1);
	}
	
	return;
}

int navigate(){
	
	int counterBomExplosionA = 0;
	int counterBomExplosionB = 0;
	int gridX, gridY;
	int z= 0;
	
	uint8_t bomX, bomY;
	
	int counterBomDeleteA = 0;
	int counterBomDeleteB = 0;
	int XA, XB, YA, YB;
	nunchukX = 1;
	nunchukY = 1;
	char bomBinnen = 0;
	int character = 1;
	Characters.MoveRed(13,13);
	while(1) {
		single_sample();
		nunchuk.update();
		XA = gridFH.GridF(nunchukX);	// hier move character A
		YA = gridFH.GridF(nunchukY);
		XB = gridFH.GridF(loopX);			// hier move character B
		YB = gridFH.GridF(loopY);

		uint8_t loopXoud = loopX;
		uint8_t loopYoud = loopY;
		
		if (loopXoud !=loopX || loopYoud !=loopX)
		{
			Characters.MoveBlue(loopX, loopY);
		}
		
		
		
		nav.navigate();
		
		if(Serial.available()>0){
			lopen = Serial.read();
			
			if(lopen == 48){
				bomBinnen = 1;
				character = 2;
				//bom.PlaceBomB(XA, YA, XB, YB, character, bomBinnen, &counterBomExplosionB, &counterBomDeleteB);
				
				}else{
				if (z == 0)
				{
					loopX = lopen;
					
				}
				if(z == 1){
					loopY =lopen;
					
				}
				z = !z;
				if(!bomBinnen){
					lcd.fillRect(gridFH.GridF(loopXoud), gridFH.GridF(loopYoud), 16, 16, WHITE); //wist vorige positie
				}
			}
		}
		harts.HartS(levensB, 16, 2);
		harts.HartS(levensA, 16, 13);
		lcd.drawInteger(255, 112, points, DEC, BLACK, WHITE, 2| 0x00);
		if (levensA == 0) {
			return 1;
		}
		if (levensB == 0) {
			return 2;
		}
		character = 1;
		bom.PlaceBomA(XA, YA, XB, YB, character, 0, &counterBomExplosionA, &counterBomDeleteA);
		character = 2;
		bom.PlaceBomB(XA, YA, XB, YB, character, bomBinnen, &counterBomExplosionB, &counterBomDeleteB);
		bomBinnen = 0;
	}
}

int level1() {
	int life;
	lcd.fillScreen(WHITE);
	wallOut.OuterWallP();
	wallIn.InnerWallP();
	OB.ObstacleDR(1, 0);
	life = navigate();
	resetGrid();
	if(life == 2) {
		winScreen();
		life = 0;
		nunchuk.update();
		
	}
	if(life == 1) {
		loseScreen();
		life = 0;
		nunchuk.update();
	}
	return;
}

int level2() {
	int life;
	lcd.fillScreen(WHITE);
	wallOut.OuterWallP();
	wallIn.InnerWallP();
	OB.ObstacleDR(2, 0);
	life = navigate();
	resetGrid();
	if(life == 2) {
		winScreen();
		life = 0;
	}
	if(life == 1) {
		loseScreen();
		
	}
	return;
}

int levelRandom(uint8_t SL) {
	lcd.fillScreen(WHITE);
	wallOut.OuterWallP();
	wallIn.InnerWallP();
	if (SL == 1)
	{
		OB.ObstacleDR(3,1);
		} else {
		OB.ObstacleDR(3,0);
	}
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
	initrw.init();
	Serial.begin(9600);
	uint8_t clear_bg=0x00; //0x80 = dont clear background for fonts (only for DisplayXXX)
	
	//init display
	lcd.begin();
	nunchuk.init();
	init_adc_single_sample();
	
	while (1)
	{
		Startscherm();
		level = navigateStart();
		if (level == 1)	{
			level1();
		}
		if (level == 2)	{
			level2();
		}
		if (level == 3)	{
			levelRandom(0);
		}
		if (level == 4)	{
			highScore();
		}
		if (level == 5)	{
			levelRandom(1);
		}
	}
}