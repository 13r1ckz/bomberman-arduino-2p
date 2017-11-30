#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <Wire.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <ArduinoNunchuk.h>
#include <EEPROM.h>

MI0283QT9 lcd;  //MI0283QT9 Adapter v1
ArduinoNunchuk nunchuk = ArduinoNunchuk();

void bomb(int X, int Y) {
	lcd.fillRect(X,Y,16,16,RGB(255,255,255));
	lcd.fillCircle((X+7),(Y+9),5,RGB(0,0,0));
	lcd.drawPixel((X+11),(Y+5),RGB(75,86,90));
	lcd.drawPixel((X+13),(Y+5),RGB(254,100,0));
	lcd.drawPixel((X+12),(Y+4),RGB(254,100,0));
	lcd.drawPixel((X+13),(Y+3),RGB(254,100,0));
	lcd.drawPixel((X+14),(Y+4),RGB(254,100,0));
	lcd.drawPixel((X+13),(Y+4),RGB(255,0,0));
	lcd.drawPixel((X+6),(Y+6),RGB(255,255,255));
	lcd.drawPixel((X+5),(Y+7),RGB(255,255,255));
	
}

int main(void)
{
	init();
	Serial.begin(9600);
	//	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	uint8_t clear_bg=0x00; //0x80 = dont clear background for fonts (only for DisplayXXX)

	//init display
	lcd.begin();
	nunchuk.init();
	lcd.fillScreen(RGB(255,255,255));
	
	while (1)
	{
		if (nunchuk.zButton) {
			bomb(0,0);		}
	}
}