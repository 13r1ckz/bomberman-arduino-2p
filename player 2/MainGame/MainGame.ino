#include <avr/io.h>
#include <avr/interrupt.h>
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
#include "lib/Navigate/Navigate.h"

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
		
		if (chat.available()){
			msg = chat.read();
			msg = msg - 48;
			if(msg == 1 || msg == 2 || msg == 3 ){
			return msg;
			}
		}
		else{
		if(nunchukY == 1){
			nav.navigatestart(1);
			if (nunchuk.zButton) {
				chat.println(1,DEC);
				return 1;
			}
		}
		
		//tekent rode rand om geselecteerde level
		if(nunchukY == 2){
			nav.navigatestart(2);
			if (nunchuk.zButton) {
				chat.println(2,DEC);
				return 2;
			}
		}
		if(nunchukY == 3){
			nav.navigatestart(3);
			
			if (nunchuk.zButton) {
				chat.println(3,DEC);
				return 3;
			}
		}
		if(nunchukY == 4){
			nav.navigatestart(4);
			
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
}

int Startscherm(){
	int level;
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
	Characters.MoveA(0,0);
	lcd.fillRect(288,0,32,16,RGB(255,255,255));
	Characters.MoveB(19,0);
	bom.BomXY(1,0);
	bom.BomXY(18,0);
	level = navigateStart();
	Serial.println(level);
	return level;
}

int loseScreen(){
	lcd.fillScreen(RGB(0,0,0));
	lcd.drawText(38,50,"You lose", RGB(255,0,0), RGB(0,0,0), 4);
	return;
}

int winScreen(){
	lcd.fillScreen(RGB(0,0,0));
	lcd.drawText(50,50,"You win", RGB(0,255,0), RGB(0,0,0), 4);
	return;
}

int navigate(){
	int levensA = 3;
	int levensB = 3;
	int nunchukY = 13;
	int nunchukX = 13;
	int counter = 8;
	int i = 0;
	int q = 0;
	int gridX, gridY;
	int bomb = 0;
	int bomX, bomY;
	int bomcounter = 75;
	int bomcounter2 = 50;
	int bomMidden = 0;
	int bomLinks = 0;
	int bomRechts = 0;
	int bomOnder = 0;
	int bomBoven = 0;
	int cBomMidden = 0;
	int cBomLinks = 0;
	int cBomRechts = 0;
	int cBomOnder = 0;
	int cBomBoven = 0;
	
	while(1) {
		  if (chat.available())
		  Serial.write(chat.read());
		single_sample();
		nunchuk.update();
		int XA = gridFH.GridF(1); // hier move character a
		int YA = gridFH.GridF(1);
		int XB = gridFH.GridF(nunchukX); //hier move caracter b
		int YB = gridFH.GridF(nunchukY);
		Characters.MoveA((XA/16),(YA/16));
		Characters.MoveB((XB/16),(YB/16));
		int gridX = 0;
		int gridY = 0;
		if (bomb==0){				//als er geen bom ligt
			if (nunchuk.zButton)
			{
				bomX=XB;
				bomY=YB;
				bomb=1;
				q=0;
				Serial.println(255, BIN);
				chat.println(255, BIN);
			}
		}
		if (bomb==1){
			bom.BomXY((bomX/16),(bomY/16));
			q++;
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
		
		if(q==bomcounter){
		
			bomMidden = 1;
			
			bom.BomExpl(bomX, bomY);
			if(!(a[bomY/16][bomX/16-1] == 2)){		//links van de bom
				bom.BomExpl((bomX-16), bomY);
				bomLinks = 1;
				
				if (a[bomY/16][bomX/16-1] == 3){	//verwijderd krat
					a[bomY/16][bomX/16-1] = 1;
				}				
			}
			if(!(a[bomY/16][bomX/16+1] == 2)){		//rechts van de bom
				bom.BomExpl((bomX+16), bomY);
				bomRechts = 1;
				
				if (a[bomY/16][bomX/16+1] == 3){	//verwijderd krat
					a[bomY/16][bomX/16+1] = 1;
				}
			}
			if(!(a[bomY/16-1][bomX/16] == 2)){		//boven van de bom
				bom.BomExpl(bomX, (bomY-16));
				bomBoven = 1;
				
				if (a[bomY/16-1][bomX/16] == 3){	//verwijderd krat
					a[bomY/16-1][bomX/16] = 1;
				}
				
			}
			if(!(a[bomY/16+1][bomX/16] == 2)){		//onder van de bom
				bom.BomExpl(bomX, (bomY+16));
				bomOnder = 1;
				
				if (a[bomY/16+1][bomX/16] == 3){	//verwijderd krat
					a[bomY/16+1][bomX/16] = 1;
				}
			}
			q=0;
			bomb = 2;
			
		}
		
		if (bomMidden == 1){		//verwijdert explosie midden
			cBomMidden++;
			if (cBomMidden == (bomcounter2+2)){
				lcd.fillRect(bomX,bomY,16,16,RGB(255,255,255));
				cBomMidden = 0;
				bomMidden = 0;
				bomb = 0;
				
				if ((XA == bomX)&&(YA == bomY))	{
					levensA--;
				}
				if ((XB == bomX)&&(YB == bomY))	{
					levensB--;
				}
			}
		}
		if (bomLinks == 1){			//verwijdert explosie links
			cBomLinks++;
			if (cBomLinks == bomcounter2){
				lcd.fillRect(bomX-16,bomY,16,16,RGB(255,255,255));
				cBomLinks = 0;
				bomLinks = 0;
				
				if ((XA == (bomX-16))&&(YA == bomY))	{ //links A
				levensA--;
				}
				if ((XB == (bomX-16))&&(YB == bomY))	{ //links B
				levensB--;
				}
			}
			
		}
		if (bomRechts == 1){		//verwijdert explosie rechts
			cBomRechts++;
			if (cBomRechts == bomcounter2){
				lcd.fillRect(bomX+16,bomY,16,16,RGB(255,255,255));
				cBomRechts = 0;
				bomRechts = 0;
				
				if ((XA == (bomX+16))&&(YA == bomY))	{
					levensA--;
				}
				if ((XB == (bomX+16))&&(YB == bomY))	{
					levensB--;
				}
			}
		}
		
		if (bomOnder == 1){			//verwijdert explosie onder
			cBomOnder++;
			if (cBomOnder == bomcounter2){
				lcd.fillRect(bomX,bomY+16,16,16,RGB(255,255,255));
				cBomOnder = 0;
				bomOnder = 0;
				
				if ((XA == bomX)&&(YA == (bomY+16)))	{
					levensA--;
				}
				if ((XB == bomX)&&(YB == (bomY-16)))	{
					levensB--;
				}
			}
		}
		
		if (bomBoven == 1){			//verwijdert explosie boven
			cBomBoven++;
			if (cBomBoven == bomcounter2){
				lcd.fillRect(bomX,bomY-16,16,16,RGB(255,255,255));
				cBomBoven = 0;
				bomBoven = 0;
				
				if ((XA == bomX)&&(YA == (bomY-16)))	{
					levensA--;
				}
				if ((XB == bomX)&&(YB == (bomY-16)))	{
					levensB--;
				}
			}
		}
		
		//omlaag lopen
		if(nunchuk.analogY < 60) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) {		//zorgt dat hij niet te snel loopt
				if (a[YB/16+1][XB/16] == 1)
				{
					nunchukY++;
					lcd.fillRect((gridFH.GridF(nunchukX)),(gridFH.GridF(nunchukY)-16), 16, 16, RGB(255,255,255)); //wist vorige positie
				}
			}
			i++;
		}
		
		//omhoog lopen
		if(nunchuk.analogY > 200) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) {	//zorgt dat hij niet te snel loopt
				if (a[YB/16-1][XB/16] == 1)
				{
					nunchukY--;
					lcd.fillRect((gridFH.GridF(nunchukX)),(gridFH.GridF(nunchukY)+16), 16, 16, RGB(255,255,255)); //wist vorige positie
				}
			}
			i++;
		}
		
		//naar links lopen
		if(nunchuk.analogX < 60) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) {	//zorgt dat hij niet te snel loopt
				if (a[YB/16][XB/16-1] == 1)
				{
					nunchukX--;
					lcd.fillRect((gridFH.GridF(nunchukX)+16),(gridFH.GridF(nunchukY)), 16, 16, RGB(255,255,255)); //wist vorige positie
				}
			}
			i++;
		}
		
		//naar rechts lopen
		if(nunchuk.analogX > 200) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) {	//zorgt dat hij niet te snel loopt
				if (a[YB/16][XB/16+1] == 1)
				{
					nunchukX++;
					lcd.fillRect((gridFH.GridF(nunchukX)-16),(gridFH.GridF(nunchukY)), 16, 16, RGB(255,255,255)); //wist vorige positie
				}
			}
			i++;
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
	navigate();
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
	chat.begin(9600);
	//	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	uint8_t clear_bg=0x00; //0x80 = dont clear background for fonts (only for DisplayXXX)

	//init display
	lcd.begin();
	nunchuk.init();
	init_adc_single_sample();
	
	while (1)
	{
		
		level = Startscherm();
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