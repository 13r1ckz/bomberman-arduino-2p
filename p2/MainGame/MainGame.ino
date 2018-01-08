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
#define DARKBLUE 0x78
#define GREEN 0x7E0
#define RED 0xFFFFF800
#define DIAMAND 0xFFFFBF9F
#define GOLD 0xFFFFFEA0
#define SILVER 0xFFFFC618
#define BRONS 0xFFFFCBE6
#define PINK 0xFFFFF8CE
#define BLOOD 0xFFFFB043

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
uint8_t bericht=0;
uint8_t level =0;
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
	ADMUX |= (0<<MUX0);		// input analog A1 Arduino
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

int reset(int soort){
	uint8_t a,b,c,d,e;
	a = eeprom_read_byte(110);
	b = eeprom_read_byte(120);
	c = eeprom_read_byte(130);
	d = eeprom_read_byte(140);
	e = eeprom_read_byte(150);
	
	if (soort == 1)
	{
		if (a >254)
		{
			eeprom_write_byte(110,0);
		}
		if (b >254)
		{
			eeprom_write_byte(120,0);
		}
		if (c >254)
		{
			eeprom_write_byte(130,0);
		}
		if (d >254)
		{
			eeprom_write_byte(140,0);
		}
		if (e >254)
		{
			eeprom_write_byte(150,0);
		}
		return;
		}else if(soort == 2){
		eeprom_write_byte(110,0);
		eeprom_write_byte(120,0);
		eeprom_write_byte(130,0);
		eeprom_write_byte(140,0);
		eeprom_write_byte(150,0);
		return;
		}else{
		return;
	}
}

int hoofdscherm(){
	lcd.fillScreen(BLACK);
	
	lcd.drawText(52,30, "BOMBERMAN", RED, BLACK, 3);
	
	lcd.fillRect(60,70,195,50,WHITE);		//print knop Level 1
	lcd.drawText(98,85, "START", DARKBLUE, WHITE, 3.5);
	
	lcd.fillRect(60,125,195,50,WHITE);		//print knop Level 2
	lcd.drawText(88,140, "HIGHSCORE", DARKBLUE, WHITE, 2);

	lcd.drawText(290, 2, "CAL", RED,BLACK, 1);
	
	Characters.MoveBlue(gridFH.GridF(1)+ 4,gridFH.GridF(2));
	Characters.MoveRed(gridFH.GridF(18)- 8,gridFH.GridF(2)+1);
	return;
}

int waitScreen(){
	char a;
	lcd.fillScreen(BLACK);
	lcd.drawText(30,110,"Wait for player 1", WHITE, BLACK, 2);
	while(!(a >= 1 && a <= 4)){
		nunchuk.update();
		if(nunchuk.zButton){
			return;
		}
		a = Serial.read() - 48;
	}
	return a;
}

int navigateHoofdscherm(){
	int nunchukY = 1;
	int counter = 5;
	int i = 0;
	
	nunchuk.update();
	
	while(!nunchuk.zButton) {
		
		nunchuk.update();
		single_sample();
		
		if (lcd.touchRead())
		{
			if((lcd.touchX() > 250) && (lcd.touchY() < 50))
			{
				lcd.touchStartCal();
				writeCalData();
				hoofdscherm();
				
			}
		}
		if(nunchuk.analogY < 60) {
			if(i>counter) {
				i=0;
			}
			if(i == 0 && nunchukY < 2) {
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
		else{
			if(nunchukY == 1){
				nav.navigateHoofdscherm(1);

			}
			if(nunchukY == 2){
				nav.navigateHoofdscherm(2); //tekent rode rand om geselecteerde level

			}
		}
	}
	
	Serial.println(nunchukY,DEC);
	return nunchukY;
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

int memory(int geheugen){
	uint8_t a,b,c,d,e;
	if (eeprom_is_ready())
	{	a = eeprom_read_byte(110);
		b = eeprom_read_byte(120);
		c = eeprom_read_byte(130);
		d = eeprom_read_byte(140);
		e = eeprom_read_byte(150);
	}

	if (points <=0)
	{
		if (points==-15)
		{
			return 6;
		}
		return 0;
	}else if (points>a)
	{
		eeprom_write_byte(150,d);
		eeprom_write_byte(140,c);
		eeprom_write_byte(130,b);
		eeprom_write_byte(120,a);
		eeprom_write_byte(110,points);
		return 1;
	}else if (points > b)
	{
		eeprom_write_byte(150,d);
		eeprom_write_byte(140,c);
		eeprom_write_byte(130,b);
		eeprom_write_byte(120,points);
		return 2;
	}else if (points > c)
	{
		eeprom_write_byte(150,d);
		eeprom_write_byte(140,c);
		eeprom_write_byte(130,points);
		return 3;
		
	}else if (points > d)
	{
		eeprom_write_byte(150,d);
		eeprom_write_byte(140,points);
		return 4;
	}else if (points > e)
	{
		eeprom_write_byte(150,points);
		return 5;
		
		}else{
		return 0;
	}
	
}

int loseScreen(){
	uint8_t m = 0;
	uint8_t geheugen;
	lcd.fillScreen(BLACK);
	lcd.drawText(35, 50, "You lose", RED, BLACK, 4);
	lcd.drawText(80, 100, "Points: ", WHITE, BLACK, 2);
	lcd.drawInteger(200, 100, points, DEC, WHITE, BLACK, 2 | 0x00);
	levensA = 3;
	levensB = 3;
	
	
	geheugen = memory(geheugen);
	if (geheugen == 0)
	{
		lcd.drawText(35, 160,"No HighScore :(", PINK,BLACK,2);
		}else if(geheugen == 6){
		lcd.drawText(50, 150,"You committed", BLOOD,BLACK,2);
		lcd.drawText(100, 170,"SUICIDE", BLOOD,BLACK,2);
		}else if (geheugen>0){
		lcd.drawText(35,140,"New Highscore!", GOLD, BLACK,2.5);
		lcd.drawText(75, 180, "Place:",GOLD, BLACK,3);
		lcd.drawInteger(220,180,geheugen,DEC,GOLD,BLACK,3|0x00);
	}
	
	while(!Serial.available()) {
		_delay_ms(1);
	}
	m = Serial.read() - 48;
	if(m == 1){
		loopX = 1;
		loopY = 1;
		bom.bombA =0;
		bom.bombB =0;
		points = 0;
		return;
	}
}

int winScreen(){
	uint8_t geheugen;
	uint8_t m = 0;
	lcd.fillScreen(BLACK);
	lcd.drawText(35, 50, "You win", GREEN, BLACK, 4);
	lcd.drawText(80, 100, "Points: ", WHITE, BLACK, 2);
	lcd.drawInteger(200, 100, points, DEC, WHITE, BLACK, 2 | 0x00);
	levensA = 3;
	levensB = 3;
	
	
	geheugen = memory(geheugen);

	if (geheugen == 0)
	{
		lcd.drawText(35, 160,"No HighScore :(", PINK,BLACK,2);
		}else if (geheugen>0){
		
		lcd.drawText(35,140,"New Highscore!", GOLD, BLACK,2.5);
		lcd.drawText(75, 180, "Place:",GOLD, BLACK,3);
		lcd.drawInteger(220,180,geheugen,DEC,GOLD,BLACK,3|0x00);
	}
	
	while(!Serial.available()) {
		_delay_ms(1);
	}
	m = Serial.read() - 48;
	if(m == 1){
		loopX = 1;
		loopY = 1;
		bom.bombA =0;
		bom.bombB =0;
		points = 0;
		return;
	}
}

int navigate(){
	
	int counterBomExplosionA = 0;
	int counterBomExplosionB = 0;
	int gridX, gridY;
	int z= 0;
	
	uint8_t bomX, bomY;
	uint8_t loopXoud;
	uint8_t loopYoud;
	int counterBomDeleteA = 0;
	int counterBomDeleteB = 0;
	int XA, XB, YA, YB;
	nunchukX = 13;
	nunchukY = 13;
	char bomBinnen = 0;
	int character = 1;
	Characters.MoveBlue(gridFH.GridF(1),gridFH.GridF(1));
	while(1) {
		single_sample();
		nunchuk.update();
		XA = gridFH.GridF(nunchukX);	// hier move character A
		YA = gridFH.GridF(nunchukY);
		XB = gridFH.GridF(loopX);			// hier move character B
		YB = gridFH.GridF(loopY);
		loopXoud = loopX;
		loopYoud = loopY;
		nav.navigate();
		Characters.MoveBlue(gridFH.GridF(loopX), gridFH.GridF(loopY));

		if(Serial.available()>0){
			if (level == 3);
			{
			uint8_t opvang = Serial.read();
			level = 0;
			}
			if(z == 0){
				bericht = Serial.read() - 48;
				z = 1;
				} else if (z == 1) {
				lopen = Serial.read() - 48;
				z = 2;
			}
			
			if(z == 2){
				if(bericht == 0){
					loopY = lopen;

					} else if(bericht == 1){
					if(lopen == 5){
						bomBinnen = 1;
						character = 2;
						z = 0;
						} else {
						loopY = lopen + 10;

					}
				}
				z = 3;
				} else if(z == 3){
				bericht = Serial.read() - 48;

				z = 4;
				} else if(z == 4){

				lopen = Serial.read() - 48;

				z = 5;
			}
			
			if(z == 5){
				if(bericht == 0){
					loopX = lopen;

					} else if(bericht == 1){
					if(lopen == 5){
						bomBinnen = 1;
						character = 2;
						z = 0;
						} else {
						loopX = lopen + 10;

					}
				}
				z = 0;
			}
			if(!bomBinnen){
				lcd.fillRect(gridFH.GridF(loopXoud), gridFH.GridF(loopYoud), 16, 16, WHITE); //wist vorige positie
			}
		}
		harts.HartS(levensB, 16, 2);
		harts.HartS(levensA, 16, 13);
		lcd.drawInteger(255, 112, points, DEC, BLACK, WHITE, 2| 0x00);
		if (levensA == 0) {
			PORTC &=~(1<<PORTC1);
			return 1;
		}
		if (levensB == 0) {
			return 2;
		}
		character = 1;
		bom.PlaceBomA(XA, YA, XB, YB, character, &counterBomExplosionA, &counterBomDeleteA);
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
	PORTC |= (1<<PORTC1) | (1<<PORTC2) | (1<<PORTC3);
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
	PORTC |= (1<<PORTC1) | (1<<PORTC2) | (1<<PORTC3);
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
	int life;
	lcd.fillScreen(WHITE);
	wallOut.OuterWallP();
	wallIn.InnerWallP();
	level = 3;
	PORTC |= (1<<PORTC1) | (1<<PORTC2) | (1<<PORTC3);
	if (SL == 1)
	{
		OB.ObstacleDR(3,1);
		} else {
		OB.ObstacleDR(3,0);
	}
	
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

int highScore() {
	uint8_t a,b,c,d,e;
	lcd.fillScreen(BLACK);
	lcd.drawText(50,30, "HIGH SCORE", PINK, BLACK, 3.5);
	
	if (eeprom_is_ready())
	{
		a = eeprom_read_byte(110);
		b = eeprom_read_byte(120);
		c = eeprom_read_byte(130);
		d = eeprom_read_byte(140);
		e = eeprom_read_byte(150);
	}
	
	lcd.drawText(100,65, "1:", DIAMAND, BLACK, 3.5);
	lcd.drawText(100,95, "2:", GOLD, BLACK, 3.5);
	lcd.drawText(100,125, "3:", SILVER, BLACK, 3.5);
	lcd.drawText(100,155, "4:", BRONS, BLACK, 3.5);
	lcd.drawText(100,185, "5:", RED, BLACK ,3.5);
	
	lcd.drawInteger(150,65, a, DEC, DIAMAND, BLACK, 3 | 0x00);
	lcd.drawInteger(150,95, b, DEC, GOLD, BLACK, 3 | 0x00);
	lcd.drawInteger(150,125, c, DEC,SILVER, BLACK, 3 | 0x00);
	lcd.drawInteger(150,155, d, DEC,BRONS, BLACK, 3 | 0x00);
	lcd.drawInteger(150,185, e, DEC,RED, BLACK, 3 | 0x00);
	
	lcd.drawText(240,200,"RESET",GREEN,BLACK,2);
	
	while(1){
		nunchuk.update();
		if (nunchuk.zButton) {
			nunchuk.update();
			return;
		}
		if (lcd.touchRead())
		{
			if (lcd.touchX()> 260 && lcd.touchX()<320 && lcd.touchY() >180 && lcd.touchY()< 240)
			{
				deletememory();
				return;
				
			}

		}

		delay(1);
	}
	return;
}

int deletememory(){
	
	int h = 0;
	
	lcd.fillRect(0,24,320,192,WHITE);
	lcd.drawText(50,26,"Delete memory?",DARKBLUE,WHITE,2.8);
	lcd.drawText(50,199,"Delete memory?",DARKBLUE,WHITE,2.8);
	lcd.drawText(35,115,"YES",DARKBLUE,WHITE,3);
	lcd.drawText(225,115,"NO",DARKBLUE,WHITE,3);
	lcd.drawRect(0,45,140,150,BLOOD);
	lcd.drawRect(180,45,320,150, BLOOD);

	while(1){
		if (h == 1)
		{
			if (lcd.touchRead())
			{
				return;
			}
		}else{
			if(lcd.touchRead()){
				if (lcd.touchX()>0 && lcd.touchX()<140 && lcd.touchY() >24 && lcd.touchY()< 192)
				{
					lcd.fillScreen(BLACK);
					
					lcd.drawText(50,90,"Memory",DARKBLUE,BLACK,3);
					lcd.drawText(50,120,"deleted",DARKBLUE,BLACK,3);
					lcd.drawText(50,180,"Press anywhere",DARKBLUE,BLACK,2);
					lcd.drawText(50,200," to continue",DARKBLUE,BLACK,2);
					reset(2);
					h= 1;
				}
				if (lcd.touchX()>180 && lcd.touchX()<320 && lcd.touchY() >24 && lcd.touchY()< 192)
				{
					lcd.fillScreen(BLACK);
					
					lcd.drawText(50,90,"Memory not",DARKBLUE,BLACK,3);
					lcd.drawText(50,120,"deleted",DARKBLUE,BLACK,3);
					lcd.drawText(50,180,"Press anywhere",DARKBLUE,BLACK,2);
					lcd.drawText(50,200," to continue",DARKBLUE,BLACK,2);
					h = 1;
				}
			}
		}
	}
	return;
}

void writeCalData(void)
{
	uint16_t i, addr=0;
	uint8_t *ptr;

	eeprom_write_byte(addr++, 0xAA);
	
	ptr = (uint8_t*)&lcd.tp_matrix;
	for(i=0; i < sizeof(CAL_MATRIX); i++)
	{
		eeprom_write_byte(addr++, *ptr++);
	}

	return;
}

uint8_t readCalData(void)
{
	uint16_t i, addr=0;
	uint8_t *ptr;
	uint8_t c;

	c = eeprom_read_byte(addr++);
	if(c == 0xAA)
	{
		ptr = (uint8_t*)&lcd.tp_matrix;
		for(i=0; i < sizeof(CAL_MATRIX); i++)
		{
			*ptr++ = eeprom_read_byte(addr++);
		}
		return 0;
	}

	return 1;
}

int main(void)
{
	char level, a;
	initrw.init();
	Serial.begin(9600);
	uint8_t clear_bg=0x00; //0x80 = dont clear background for fonts (only for DisplayXXX)
	//init display
	lcd.begin();
	nunchuk.init();
	init_adc_single_sample();
	reset(1);
	DDRC |=(1<<DDC1) | (1<<DDC2) | (1<<DDC3);
	lcd.touchRead();
	if(lcd.touchZ() || readCalData()) //calibration data in EEPROM?
	{
		lcd.touchStartCal(); //calibrate touchpanel
		writeCalData(); //write data to EEPROM
	};
	
	while (1)
	{
		hoofdscherm();
		a = navigateHoofdscherm();
		if(a == 1){
			level = waitScreen();
			if (level == 1)	{
				level1();
			}
			if (level == 2)	{
				level2();
			}
			if (level == 3)	{
				levelRandom(1);
			}
			if (level == 4){
				a = 0;
				level = 0;
			}
			level = 0;
			
			} else if (a == 2){
			highScore();
		}
	}
}