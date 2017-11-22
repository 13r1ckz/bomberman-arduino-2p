#include <avr/io.h>
#include <Wire.h>
#include <ArduinoNunchuk.h>
//#define BAUDRATE 19200;

ArduinoNunchuk nunchuk = ArduinoNunchuk();

int main(void) {
	init();
	Serial.begin(19200);
	nunchuk.init();
	int nunchukY = 0;
	int counter = 30;
	
	int i = 0;
	
	while(1){
		nunchuk.update();
		if(nunchuk.analogY < 60) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) {
				nunchukY--;
				i++;
			}
			i++;		
		}
		
		if(nunchuk.analogY > 200) {
			if(i>counter) {
				i=0;
			}
			if(i == 0) {
				nunchukY++;
				i++;
			}
			i++;
		}
		Serial.print(nunchuk.analogY, DEC);
		Serial.print(' ');
		Serial.println(nunchukY, DEC);
		
		
		
		/*Serial.print(nunchuk.analogX, DEC);
		Serial.print(' ');
		
		
		Serial.print(nunchuk.zButton, DEC);
		Serial.print(' ');
		Serial.println(nunchuk.cButton, DEC);*/
	}
}