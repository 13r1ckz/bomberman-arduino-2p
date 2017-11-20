/*
 * Gamegrid.ino
 *
 * Created: 11/20/2017 12:42:59 PM
 * Author : gerjon
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <Wire.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>

//Declare display !
MI0283QT9 lcd;  //MI0283QT9 Adapter v1

void OuterWall(){
	int i , j;
	int X = 0;
	int Y = 0;
	
	for(i = 0; i < 15; i++){
		lcd.fillRect(X,Y,16,16, 0xFFFFFF);
		lcd.fillRect((X+1),(Y+1),14,14, 0x000);
		X = X + 16;
	}
	for(i = 0; i < 16; i++){
		lcd.fillRect(0,Y,16,16, 0xFFFFFF);
		lcd.fillRect(1,(Y+1),14,14, 0x000);
		lcd.fillRect(224,Y,16,16, 0xFFFFFF);
		lcd.fillRect(225,(Y+1),14,14, 0x000);
		Y = Y + 16;
	}
	X = 0;
	for(i = 0; i < 15; i++){
		lcd.fillRect(X,224,16,16, 0xFFFFFF);
		lcd.fillRect((X+1),(225),14,14, 0x000);
		X = X + 16;
	}
	X = 32;
	Y = 32;
	for(i = 0; i < 6; i++){
		for(j = 0; j < 6; j++){
			lcd.fillRect((X),(Y),16,16, 0x000);
			X = X + 32;
			Serial.println("X");
		}
		X = 32;
		Y = Y + 32;
		Serial.println("Y");
	}
}

int main(void)
{
    init();
    Serial.begin(9600);   
    //	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
    uint8_t clear_bg=0x00; //0x80 = dont clear background for fonts (only for DisplayXXX)

    //init display
    lcd.begin();

    //clear screen
    lcd.fillScreen(RGB(255,255,255));
	OuterWall();
    while (1) 
    {
		
    }
}