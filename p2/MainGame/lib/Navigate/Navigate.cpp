#include "Navigate.h"
#define WHITE 0xFFFFFFFF
#define RED 0xFFFFF800
Navigate::navigate()
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	ArduinoNunchuk nunchuk = ArduinoNunchuk();

	GridClass gridFH;
	Character Characters;
	Serial.begin(9600);
	nunchuk.update();
	int time = 8;
	Characters.MoveRed(gridFH.GridF(nunchukX),gridFH.GridF(nunchukY));
	if(nunchuk.analogY < 60) { //omlaag lopen
		if(counter > time) {
			counter=0;
		}
		if(counter == 0) {		//zorgt dat hij niet te snel loopt
			if (a[nunchukY+1][nunchukX] == 1)
			{
				nunchukY++;
				if (nunchukX <10)
				{Serial.print(0,DEC);
					Serial.print(nunchukX, DEC);
					}else{
					Serial.print(nunchukX, DEC);
				}
				
				if (nunchukY <10)
				{	Serial.print(0,DEC);
					Serial.print(nunchukY, DEC);
					}else{
					Serial.print(nunchukY, DEC);
				}
				
				
				lcd.fillRect(gridFH.GridF(nunchukX), gridFH.GridF(nunchukY)-16, 16, 16, WHITE); //wist vorige positie
			}
		}
		counter++;
	}
	
	if(nunchuk.analogY > 200) { //omhoog lopen
		if(counter > time) {
			counter=0;
		}
		if(counter == 0) {	//zorgt dat hij niet te snel loopt
			if (a[nunchukY-1][nunchukX] == 1)
			{
				nunchukY--;
				if (nunchukX <10)
				{Serial.print(0,DEC);
					Serial.print(nunchukX, DEC);
					}else{
					Serial.print(nunchukX, DEC);
				}
				
				if (nunchukY <10)
				{	Serial.print(0,DEC);
					Serial.print(nunchukY, DEC);
					}else{
					Serial.print(nunchukY, DEC);
				}
				lcd.fillRect(gridFH.GridF(nunchukX), gridFH.GridF(nunchukY)+16, 16, 16, WHITE); //wist vorige positie
			}
		}
		counter++;
	}
	
	if(nunchuk.analogX < 60) { //naar links lopen
		if(counter > time) {
			counter=0;
		}
		if(counter == 0) {	//zorgt dat hij niet te snel loopt
			if (a[nunchukY][nunchukX-1] == 1)
			{
				nunchukX--;
				if (nunchukX <10)
				{	Serial.print(0,DEC);
					Serial.print(nunchukX, DEC);
					}else{
					Serial.print(nunchukX, DEC);
				}
				
				if (nunchukY <10)
				{	Serial.print(0,DEC);
					Serial.print(nunchukY, DEC);
					}else{
					Serial.print(nunchukY, DEC);
				}
				lcd.fillRect(gridFH.GridF(nunchukX)+16, gridFH.GridF(nunchukY), 16, 16, WHITE); //wist vorige positie
			}
		}
		counter++;
	}
	
	if(nunchuk.analogX > 200) { //naar rechts lopen
		if(counter > time) {
			counter=0;
		}
		if(counter == 0) {	//zorgt dat hij niet te snel loopt
			if (a[nunchukY][nunchukX+1] == 1)
			{
				nunchukX++;
				if (nunchukX <10)
				{Serial.print(0,DEC);
					Serial.print(nunchukX, DEC);
					}else{
					Serial.print(nunchukX, DEC);
				}
				
				if (nunchukY <10)
				{	Serial.print(0,DEC);
					Serial.print(nunchukY, DEC);
					}else{
					Serial.print(nunchukY, DEC);
				}
				lcd.fillRect(gridFH.GridF(nunchukX)-16, gridFH.GridF(nunchukY), 16, 16, WHITE); //wist vorige positie
			}
		}
		counter++;
	}
} //Navigate


Navigate::navigatestart(char button)
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	if(button == 1){
		lcd.drawRect(60, 180, 200, 50, WHITE);
		lcd.drawRect(61, 181, 198, 48, WHITE);
		lcd.drawRect(62, 182, 196, 46, WHITE);
		
		lcd.drawRect(60, 70, 200, 50, WHITE);
		lcd.drawRect(61, 71, 198, 48, WHITE);
		lcd.drawRect(62, 72, 196, 46, WHITE);
		
		lcd.drawRect(60, 15, 200, 50, RED);
		lcd.drawRect(61, 16, 198, 48, RED);
		lcd.drawRect(62, 17, 196, 46, RED);
	}
	else if(button == 2){
		lcd.drawRect(60, 15, 200, 50, WHITE);
		lcd.drawRect(61, 16, 198, 48, WHITE);
		lcd.drawRect(62, 17, 196, 46, WHITE);
		
		lcd.drawRect(60, 125, 200, 50, WHITE);
		lcd.drawRect(61, 126, 198, 48, WHITE);
		lcd.drawRect(62, 127, 196, 46, WHITE);
		
		lcd.drawRect(60, 70, 200, 50, RED);
		lcd.drawRect(61, 71, 198, 48, RED);
		lcd.drawRect(62, 72, 196, 46, RED);
	}
	else if(button == 3){
		lcd.drawRect(60, 70, 200, 50, WHITE);
		lcd.drawRect(61, 71, 198, 48, WHITE);
		lcd.drawRect(62, 72, 196, 46, WHITE);
		
		lcd.drawRect(60, 180, 200, 50, WHITE);
		lcd.drawRect(61, 181, 198, 48, WHITE);
		lcd.drawRect(62, 182, 196, 46, WHITE);
		
		lcd.drawRect(60, 125, 200, 50, RED);
		lcd.drawRect(61, 126, 198, 48, RED);
		lcd.drawRect(62, 127, 196, 46, RED);
	}
	else if(button == 4){
		lcd.drawRect(60, 125, 200, 50, WHITE);
		lcd.drawRect(61, 126, 198, 48, WHITE);
		lcd.drawRect(62, 127, 196, 46, WHITE);
		
		lcd.drawRect(60, 15, 200, 50, WHITE);
		lcd.drawRect(61, 16, 198, 48, WHITE);
		lcd.drawRect(62, 17, 196, 46, WHITE);
		
		lcd.drawRect(60, 180, 200, 50, RED);
		lcd.drawRect(61, 181, 198, 48, RED);
		lcd.drawRect(62, 182, 196, 46, RED);
	}
	else{
		lcd.drawText(20,20, "enter number between 1 and 4", RED,RED,3);
	}
} //Navigatestart


