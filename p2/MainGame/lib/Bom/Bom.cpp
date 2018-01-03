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

void Bom::PlaceBomA(int XA, int YA, int XB, int YB, int character, int bomBinnen, int * counterBomExplosionA, int * counterBomDeleteA)
{
	MI0283QT9 lcd;
	ArduinoNunchuk nunchuk;
	
	int bomExplosion = 40;
	int bomDelete = 40;
	nunchuk.update();


	if (bombA==0){				//als er geen bom ligt
		
		if (nunchuk.zButton) {
					bomX=XA;
					bomY=YA;
				
					
			bombA=1;
			*counterBomExplosionA=0;
			
		}
	}
	if (bombA==1 || bomBinnen == 1) {
		BomXY(bomX/16, bomY/16);
		*counterBomExplosionA+=1;
		bomBinnen = 0;

	}
	
	if(*counterBomExplosionA==bomExplosion) {
		BomTrack(bomX, bomY, character);
		*counterBomExplosionA=0;
		bombA = 2;
	}
	
	if (bombA == 2) {
		*counterBomDeleteA+=1;
		if (*counterBomDeleteA == bomDelete) {
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
			bombA = 0;
			*counterBomDeleteA = 0;
		}
		
	}
	
	
}
void Bom::PlaceBomB(int XA, int YA, int XB, int YB, int character, int bomBinnen, int * counterBomExplosionB, int * counterBomDeleteB)
{
	MI0283QT9 lcd;
	ArduinoNunchuk nunchuk;
	
	
	int bomExplosion = 40;
	int bomDelete = 40;
	nunchuk.update();
	
	
		
	
	
if(bomBinnen ==1 ){
	bomX=XB;
	bomY=YB;
	bombB = 1;
	
		
}

	if (bombB==1) {
		BomXY(bomX/16, bomY/16);
		*counterBomExplosionB+=1;
		bomBinnen = 0;
		

	}
	
	if(*counterBomExplosionB==bomExplosion) {
		BomTrack(bomX, bomY, character);
		*counterBomExplosionB=0;
		bombB = 2;
	}
	
	if (bombB == 2) {
		*counterBomDeleteB+=1;
		if (*counterBomDeleteB == bomDelete) {
			if ((((XA == bomX) || (XA == bomX-16) || (XA == bomX+16)) && (YA == bomY)) || ((XA == bomX) && ((YA == bomY) || (YA == bomY-16) || (YA == bomY+16))))	{ //character A midden in bom
				levensA--;
				lcd.fillRect(255, 112,100, 50, WHITE);
			
			}
			if ((((XB == bomX) || (XB == bomX-16) || (XB == bomX+16)) && (YB == bomY)) || ((XB == bomX) && ((YB == bomY) || (YB == bomY-16) || (YB == bomY+16))))	{ //character B midden in bom
				levensB--;
			
			}
			BomDelete(bomX, bomY, character);
			bombB = 0;
			*counterBomDeleteB = 0;
		}
		
	}
	
	
}