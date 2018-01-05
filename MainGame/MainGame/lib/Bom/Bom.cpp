#include "Bom.h"
#define BLACK 0x000000
#define DARKGREY 0x49CB
#define LIGHTERORANGE 0xFFFFFBC6
#define LIGHTORANGE 0xFFFFFA81
#define ORANGE 0xFFFFFB20
#define TERRACOTTA 0xFFFFFD4B
#define LIGHTRED 0xFFFFF800
#define RED 0xFFFFD000
#define DARKRED 0xFFFFA000
#define WHITECREAM 0xFFFFFFF5
#define WHITE 0xFFFFFF
// default constructor
Bom::BomXY(int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	
	
	//lcd.fillRect(gridFH.GridF(X),gridFH.GridF(Y),16,16,WHITE);
	lcd.fillCircle((X+7),(Y+9),5,BLACK);
	lcd.drawPixel((X+11),(Y+5),DARKGREY);
	lcd.drawPixel((X+13),(Y+5),ORANGE);
	lcd.drawPixel((X+12),(Y+4),ORANGE);
	lcd.drawPixel((X+13),(Y+3),ORANGE);
	lcd.drawPixel((X+14),(Y+4),ORANGE);
	lcd.drawPixel((X+13),(Y+4),LIGHTRED);
	lcd.drawPixel((X+6),(Y+6),WHITE);
	lcd.drawPixel((X+5),(Y+7),WHITE);
} //Bom

Bom::BomExpl(int X, int Y)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1

	lcd.fillRect(X, Y, 16, 16, DARKRED);
	lcd.fillRect((X+1), (Y+1), 14, 14, RED);
	lcd.fillRect((X+2), (Y+2), 12, 12, LIGHTORANGE);
	lcd.fillRect((X+3), (Y+3), 10, 10, LIGHTERORANGE);
	lcd.fillRect((X+4), (Y+4), 8, 8, TERRACOTTA);
	lcd.fillRect((X+5), (Y+5), 6, 6, WHITECREAM);
	lcd.fillRect((X+6), (Y+6), 4, 4, WHITE);
	
}//explosion

Bom::BomTrackA(int bomX, int bomY, int character) //kratten verwijderen+punten tellen
{
	BomExpl(bomX, bomY);
	if(!(a[bomY/16][bomX/16-1] == 2)) {		//links van de bom
		BomExpl(bomX-16, bomY);
		
		if (a[bomY/16][bomX/16-1] == 3) {	//verwijderd krat
			a[bomY/16][bomX/16-1] = 1;
			
			if(character == 1) {
				lcd.fillRect(240, 100,100, 50, WHITE);
				points +=2;
			}
		}
	}
	if(!(a[bomY/16][bomX/16+1] == 2)) {		//rechts van de bom
		BomExpl(bomX+16, bomY);
		
		if (a[bomY/16][bomX/16+1] == 3) {	//verwijderd krat
			a[bomY/16][bomX/16+1] = 1;
			
			if(character == 1) {
				lcd.fillRect(240, 100,100, 50, WHITE);
				points +=2;
			}
		}
	}
	if(!(a[bomY/16-1][bomX/16] == 2)) {		//boven van de bom
		BomExpl(bomX, bomY-16);
		
		if (a[bomY/16-1][bomX/16] == 3) {	//verwijderd krat
			a[bomY/16-1][bomX/16] = 1;
			
			if(character == 1) {
				lcd.fillRect(240, 100,100, 50, WHITE);
				points +=2;
			}
		}
		
	}
	if(!(a[bomY/16+1][bomX/16] == 2)) {		//onder van de bom
		BomExpl(bomX, bomY+16);
		
		if (a[bomY/16+1][bomX/16] == 3) {	//verwijderd krat
			a[bomY/16+1][bomX/16] = 1;
			
			if(character == 1) {
				lcd.fillRect(240, 100,100, 50, WHITE);
				points +=2;
			}
		}
	}
}

Bom::BomDelete(int bomX, int bomY)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	
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

void Bom::PlaceBomA(int XA, int YA, int XB, int YB, int character, int * counterBomExplosionA, int * counterBomDeleteA)
{
	MI0283QT9 lcd;
	ArduinoNunchuk nunchuk;
	
	int bomExplosion = 40;
	int bomDelete = 40;
	nunchuk.update();
	
	if (bombA==0){				//als er geen bom ligt
		if (nunchuk.zButton) {
			bomXA=XA;
			bomYA=YA;
			bombA=1;
			*counterBomExplosionA=0;
			Serial.print(15, DEC);
			Serial.print(15, DEC);
		}
	}
	if (bombA==1) {
		BomXY(bomXA, bomYA);
		*counterBomExplosionA+=1;
	}
	if(*counterBomExplosionA==bomExplosion) {
		BomTrackA(bomXA, bomYA, character);
		*counterBomExplosionA=0;
		bombA = 2;
	}
	
	if (bombA == 2) {
		*counterBomDeleteA+=1;
		if (*counterBomDeleteA == bomDelete) {
			if ((((XA == bomXA) || (XA == bomXA-16) || (XA == bomXA+16)) && (YA == bomYA)) || ((XA == bomXA) && ((YA == bomYA) || (YA == bomYA-16) || (YA == bomYA+16))))	{ //character A midden in bom
				levensA--;
				lcd.fillRect(240, 100,100, 50, WHITE);
				points -= 5;
			}
			if ((((XB == bomXA) || (XB == bomXA-16) || (XB == bomXA+16)) && (YB == bomYA)) || ((XB == bomXA) && ((YB == bomYA) || (YB == bomYA-16) || (YB == bomYA+16))))	{ //character B midden in bom
				levensB--;
				lcd.fillRect(240, 100,100, 50, WHITE);
				points += 10;
			}
			BomDelete(bomXA, bomYA);
			bombA = 0;
			*counterBomDeleteA = 0;
		}
		
	}
	
	
}

void Bom::PlaceBomB(int XA, int YA, int XB, int YB, int character, int bomBinnen, int * counterBomExplosionB, int * counterBomDeleteB)
{
	MI0283QT9 lcd;
	
	int bomExplosion = 40;
	int bomDelete = 40;

	if(bomBinnen ==1 ){
		bomXB=XB;
		bomYB=YB;
		bombB = 1;
	}

	if (bombB==1) {
		BomXY(bomXB, bomYB);
		*counterBomExplosionB+=1;
		bomBinnen = 0;
	}
	if(*counterBomExplosionB==bomExplosion) {
		BomTrackB(bomXB, bomYB, character);
		*counterBomExplosionB=0;
		bombB = 2;
	}
	if (bombB == 2) {
		*counterBomDeleteB+=1;
		if (*counterBomDeleteB == bomDelete) {
			if ((((XA == bomXB) || (XA == bomXB-16) || (XA == bomXB+16)) && (YA == bomYB)) || ((XA == bomXB) && ((YA == bomYB) || (YA == bomYB-16) || (YA == bomYB+16))))	{ //character A midden in bom
				levensA--;
				lcd.fillRect(255, 112,100, 50, WHITE);
			}
			if ((((XB == bomXB) || (XB == bomXB-16) || (XB == bomXB+16)) && (YB == bomYB)) || ((XB == bomXB) && ((YB == bomYB) || (YB == bomYB-16) || (YB == bomYB+16))))	{ //character B midden in bom
				levensB--;
			}
			BomDelete(bomXB, bomYB);
			bombB = 0;
			*counterBomDeleteB = 0;
		}
	}
}

Bom::BomTrackB(int bomX, int bomY, int character) //Bom verwijderen+punten tellen
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