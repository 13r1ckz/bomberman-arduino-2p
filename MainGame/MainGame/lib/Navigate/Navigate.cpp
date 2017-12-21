#include "Navigate.h"
#define WHITE 0xFFFFFFFF

Navigate::navigate()
{
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	ArduinoNunchuk nunchuk = ArduinoNunchuk();
	SoftwareSerial chat(2, 3); // RX, TX
	GridClass gridFH;
	Character Characters;
	nunchuk.update();
	int time = 8;
	Characters.MoveA(nunchukX, nunchukY);
	if(nunchuk.analogY < 60) { //omlaag lopen
		if(counter > time) {
			counter=0;
		}
		if(counter == 0) {		//zorgt dat hij niet te snel loopt
			if (a[nunchukY+1][nunchukX] == 1)
			{
				nunchukY++;
				chat.println(nunchukX, BIN);
				//Serial.print("X: ");
				//Serial.println(nunchukX, BIN);
				chat.println(nunchukY, BIN);
				//Serial.print("Y: ");
				//Serial.println(nunchukY, BIN);
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
				chat.println(nunchukX, BIN);
				//Serial.print("X: ");
				//Serial.println(nunchukX, BIN);
				chat.println(nunchukY, BIN);
				//Serial.print("Y: ");
				//Serial.println(nunchukY, BIN);
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
				chat.println(nunchukX, BIN);
				//Serial.print("X: ");
				//Serial.println(nunchukX, BIN);
				chat.println(nunchukY, BIN);
				//Serial.print("Y: ");
				//Serial.println(nunchukY, BIN);
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
				chat.println(nunchukX, BIN);
				//Serial.print("X: ");
				//Serial.println(nunchukX, BIN);
				chat.println(nunchukY, BIN);
				//Serial.print("Y: ");
				//Serial.println(nunchukY, BIN);
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
		lcd.drawRect(60, 180, 200, 50, RGB(255,255,255));
		lcd.drawRect(61, 181, 198, 48, RGB(255,255,255));
		lcd.drawRect(62, 182, 196, 46, RGB(255,255,255));
		
		lcd.drawRect(60, 70, 200, 50, RGB(255,255,255));
		lcd.drawRect(61, 71, 198, 48, RGB(255,255,255));
		lcd.drawRect(62, 72, 196, 46, RGB(255,255,255));
		
		lcd.drawRect(60, 15, 200, 50, RGB(255,0,0));
		lcd.drawRect(61, 16, 198, 48, RGB(255,0,0));
		lcd.drawRect(62, 17, 196, 46, RGB(255,0,0));
	}
	else if(button == 2){
		lcd.drawRect(60, 15, 200, 50, RGB(255,255,255));
		lcd.drawRect(61, 16, 198, 48, RGB(255,255,255));
		lcd.drawRect(62, 17, 196, 46, RGB(255,255,255));
		
		lcd.drawRect(60, 125, 200, 50, RGB(255,255,255));
		lcd.drawRect(61, 126, 198, 48, RGB(255,255,255));
		lcd.drawRect(62, 127, 196, 46, RGB(255,255,255));
		
		lcd.drawRect(60, 70, 200, 50, RGB(255,0,0));
		lcd.drawRect(61, 71, 198, 48, RGB(255,0,0));
		lcd.drawRect(62, 72, 196, 46, RGB(255,0,0));
	}
	else if(button == 3){
		lcd.drawRect(60, 70, 200, 50, RGB(255,255,255));
		lcd.drawRect(61, 71, 198, 48, RGB(255,255,255));
		lcd.drawRect(62, 72, 196, 46, RGB(255,255,255));
		
		lcd.drawRect(60, 180, 200, 50, RGB(255,255,255));
		lcd.drawRect(61, 181, 198, 48, RGB(255,255,255));
		lcd.drawRect(62, 182, 196, 46, RGB(255,255,255));
		
		lcd.drawRect(60, 125, 200, 50, RGB(255,0,0));
		lcd.drawRect(61, 126, 198, 48, RGB(255,0,0));
		lcd.drawRect(62, 127, 196, 46, RGB(255,0,0));
	}
	else if(button == 4){
		lcd.drawRect(60, 125, 200, 50, RGB(255,255,255));
		lcd.drawRect(61, 126, 198, 48, RGB(255,255,255));
		lcd.drawRect(62, 127, 196, 46, RGB(255,255,255));
		
		lcd.drawRect(60, 15, 200, 50, RGB(255,255,255));
		lcd.drawRect(61, 16, 198, 48, RGB(255,255,255));
		lcd.drawRect(62, 17, 196, 46, RGB(255,255,255));
		
		lcd.drawRect(60, 180, 200, 50, RGB(255,0,0));
		lcd.drawRect(61, 181, 198, 48, RGB(255,0,0));
		lcd.drawRect(62, 182, 196, 46, RGB(255,0,0));
	}
	else{
		lcd.drawText(20,20, "enter number between 1 and 4", RGB(255,0,0),RGB(255,0,0),3);
	}
} //Navigatestart