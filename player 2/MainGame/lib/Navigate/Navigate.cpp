#include "Navigate.h"

Navigate::navigate()
{
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