/* 
* Bom.cpp
*
* Created: 11/30/2017 11:26:54 AM
* Author: gerjo
*/


#include "Bom.h"

// default constructor
Bom::BomXY(int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	
	//lcd.fillRect(gridFH.GridF(X),gridFH.GridF(Y),16,16,RGB(255,255,255));
	lcd.fillCircle((gridFH.GridF(X)+7),(gridFH.GridF(Y)+9),5,RGB(0,0,0));
	lcd.drawPixel((gridFH.GridF(X)+11),(gridFH.GridF(Y)+5),RGB(75,86,90));
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+5),RGB(254,100,0));
	lcd.drawPixel((gridFH.GridF(X)+12),(gridFH.GridF(Y)+4),RGB(254,100,0));
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+3),RGB(254,100,0));
	lcd.drawPixel((gridFH.GridF(X)+14),(gridFH.GridF(Y)+4),RGB(254,100,0));
	lcd.drawPixel((gridFH.GridF(X)+13),(gridFH.GridF(Y)+4),RGB(255,0,0));
	lcd.drawPixel((gridFH.GridF(X)+6),(gridFH.GridF(Y)+6),RGB(255,255,255));
	lcd.drawPixel((gridFH.GridF(X)+5),(gridFH.GridF(Y)+7),RGB(255,255,255));
} //Bom

Bom::BomExpl(int X, int Y)
{
		MI0283QT9 lcd;  //MI0283QT9 Adapter v1
		GridClass gridFH;
		lcd.fillRect(X, Y, 16, 16, RGB(164,0,0));
		lcd.fillRect((X+1), (Y+1), 14, 14, RGB(214,0,0));
		lcd.fillRect((X+2), (Y+2), 12, 12, RGB(255,80,10));
		lcd.fillRect((X+3), (Y+3), 10, 10, RGB(255,120,50));
		lcd.fillRect((X+4), (Y+4), 8, 8, RGB(255,170,90));
		lcd.fillRect((X+5), (Y+5), 6, 6, RGB(255,255,170));
		lcd.fillRect((X+6), (Y+6), 4, 4, RGB(255,255,255));
				
}//explosion

Bom::BomTrack(int bomX, int bomY, int character) 
{
	BomExpl(bomX, bomY);
	if(!(a[bomY/16][bomX/16-1] == 2)) {		//links van de bom
		BomExpl(bomX-16, bomY);
		
		if (a[bomY/16][bomX/16-1] == 3) {	//verwijderd krat
			a[bomY/16][bomX/16-1] = 1;
			
			if(character == 1) {
				points +=2;
			}
		}
	}
	if(!(a[bomY/16][bomX/16+1] == 2)) {		//rechts van de bom
		BomExpl(bomX+16, bomY);
		
		if (a[bomY/16][bomX/16+1] == 3) {	//verwijderd krat
			a[bomY/16][bomX/16+1] = 1;
			
			if(character == 1) {
				points +=2;
			}
		}
	}
	if(!(a[bomY/16-1][bomX/16] == 2)) {		//boven van de bom
		BomExpl(bomX, bomY-16);
		
		if (a[bomY/16-1][bomX/16] == 3) {	//verwijderd krat
			a[bomY/16-1][bomX/16] = 1;
			
			if(character == 1) {
				points +=2;
			}
		}
		
	}
	if(!(a[bomY/16+1][bomX/16] == 2)) {		//onder van de bom
		BomExpl(bomX, bomY+16);
		
		if (a[bomY/16+1][bomX/16] == 3) {	//verwijderd krat
			a[bomY/16+1][bomX/16] = 1;
			
			if(character == 1) {
				points +=2;
			}
		}
	}
}

Bom::BomDelete(int bomX, int bomY, int character) 
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	#define WHITE 0xFFFFFFFF
	lcd.fillRect(bomX, bomY, 16, 16, WHITE); //midden van de bom
	
	if(!(a[bomY/16][bomX/16-1] == 2)) {		//links van de bom
		lcd.fillRect(bomX-16, bomY, 16, 16, WHITE);
	}
	
	if(!(a[bomY/16][bomX/16+1] == 2)) {		//rechts van de bom
		lcd.fillRect(bomX+16, bomY, 16, 16, WHITE);
	}
	
	if(!(a[bomY/16-1][bomX/16] == 2)) {		//boven van de bom
		lcd.fillRect(bomX, bomY-16, 16, 16, WHITE);
	}
	
	if(!(a[bomY/16+1][bomX/16] == 2)) {		//onder van de bom
		lcd.fillRect(bomX, bomY+16, 16, 16, WHITE);
	}
}

void Bom::PlaceBom(int XA, int YA, int XB, int YB, int character, int bomBinnen, int * counterBomExplosion, int * counterBomDelete)
{
	MI0283QT9 lcd;
	ArduinoNunchuk nunchuk;
	SoftwareSerial chat(2, 3); // RX, TX
	
	int bomExplosion = 75;
	int bomDelete = 50;
	nunchuk.update();
	
	if (bomb==0){				//als er geen bom ligt
		//Serial.println(nunchuk.zButton);
		if (nunchuk.zButton) {
			if (character == 1) {
				bomX=XA;
				bomY=YA;
			} else if (character == 2) {
				bomX=XB;
				bomY=YB;
			}
			bomb=1;
			*counterBomExplosion=0;
			Serial.println(255,BIN);
			chat.println(255,BIN);
		}
	}
	if (bomb==1 || bomBinnen == 1) {
		BomXY(bomX/16, bomY/16);
		*counterBomExplosion+=1;
		bomBinnen = 0;

	}
	
	if(*counterBomExplosion==bomExplosion) {
		BomTrack(bomX, bomY, character);
		*counterBomExplosion=0;
		bomb = 2;
	}
	
	if (bomb == 2) {
		*counterBomDelete+=1;
		if (*counterBomDelete == bomDelete) {
			if ((((XA == bomX) || (XA == bomX-16) || (XA == bomX+16)) && (YA == bomY)) || ((XA == bomX) && ((YA == bomY) || (YA == bomY-16) || (YA == bomY+16))))	{ //character A midden in bom
				levensA--;
				lcd.fillRect(255, 112,100, 50, WHITE);
				points -= 5;
			}
			if ((((XB == bomX) || (XB == bomX-16) || (XB == bomX+16)) && (YB == bomY)) || ((XB == bomX) && ((YB == bomY) || (YB == bomY-16) || (YB == bomY+16))))	{ //character B midden in bom
				levensB--;
				points += 10;
			}
			BomDelete(bomX, bomY, character);
			bomb = 0;
			*counterBomDelete = 0;
		}
		
	}
	
	
}