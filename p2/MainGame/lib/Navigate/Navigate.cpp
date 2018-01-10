#include "Navigate.h"
#define WHITE 0xFFFFFFFF
#define RED 0xFFFFF800

/*
Met deze functie kan het poppetje bewegen
*/
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
/*
Met deze functie wordt de rode rand getekend
*/
 Navigate::navigateHoofdscherm(char button){
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	if(button == 1){

		
		lcd.drawRect(60, 125, 195, 50, WHITE);
		lcd.drawRect(61, 126, 193, 48, WHITE);
		lcd.drawRect(62, 127, 191, 46, WHITE);
		
		lcd.drawRect(60, 70, 195, 50, RED);
		lcd.drawRect(61, 71, 193, 48, RED);
		lcd.drawRect(62, 72, 191, 46, RED);
		} else if(button == 2){
		lcd.drawRect(60, 70, 195, 50, WHITE);
		lcd.drawRect(61, 71, 193, 48, WHITE);
		lcd.drawRect(62, 72, 191, 46, WHITE);
		
		lcd.drawRect(60, 125, 195, 50, RED);
		lcd.drawRect(61, 126, 193, 48, RED);
		lcd.drawRect(62, 127, 191, 46, RED);
	}
}
