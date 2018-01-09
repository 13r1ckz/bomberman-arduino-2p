#include "Obstacle.h"

#define LIGHTBROWN 0xFFFFAC08
#define WINDESHEIM 0xFFFFD501
#define DARKBROWN 0x6A82

Obstacle::woodBox(int X, int Y){
	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
	GridClass gridFH;
	lcd.fillRect(gridFH.GridF(X), gridFH.GridF(Y), 16, 16, LIGHTBROWN);
	lcd.drawRect((gridFH.GridF(X)+3), gridFH.GridF(Y), 2, 16, WINDESHEIM);
	lcd.drawRect((gridFH.GridF(X)+7), gridFH.GridF(Y), 2, 16, WINDESHEIM);
	lcd.drawRect((gridFH.GridF(X)+11), gridFH.GridF(Y), 2, 16,WINDESHEIM);
	lcd.drawRect(gridFH.GridF(X), gridFH.GridF(Y), 16, 16, DARKBROWN);
	a[Y][X] = 3;
	
}

Obstacle::ObstacleDR(int level, uint8_t SR)
{
	Serial.begin(9600);
	char i;
	
	if(level == 1){
		woodBox(4,1);
		for(i = 7; i <= 10; i++){ //rij 1
			woodBox(i, 1);
		}
		for(i = 3; i <=11 ; i+=2){//rij 2
			woodBox(i,2);
		}
		woodBox(2,3);
		woodBox(4,3);
		woodBox(7,3);
		woodBox(8,3);
		woodBox(10,3);
		woodBox(11,3);
		for(i = 3; i <=13 ; i+=2){//rij 4
			woodBox(i,4);
		}
		for (i = 2; i <= 13; i++){//rij 5
			woodBox(i, 5);
		}
		for(i = 1; i <=13 ; i+=2){//rij 6
			woodBox(i,6);
		}
		woodBox(1,7);
		for (i = 3; i <= 13; i++){//rij 7
			woodBox(i, 7);
		}

		for(i = 1; i <=11 ; i+=2){//rij 8
			woodBox(i,8);
		}
		woodBox(2,9);
		woodBox(4,9);
		woodBox(5,9);
		woodBox(7,9);
		woodBox(9,9);
		woodBox(11,9);
		woodBox(12,9);
		
		woodBox(3,10);
		woodBox(9,10);
		woodBox(11,10);
		for (i = 4; i <= 11; i++){//rij 11
			if(!(i == 8)){
				woodBox(i, 11);
			}
		}
		for(i = 1; i <=9 ; i+=2){//rij 12
			woodBox(i,12);
		}
		
		woodBox(1,13);
		woodBox(2,13);
		woodBox(5,13);
		woodBox(7,13);
		woodBox(10,13);
		woodBox(11,13);
	}
	else if (level == 2){
		for (i = 1; i <= 13; i++){//rij 5/7/9
			woodBox(i, 5);
			woodBox(i, 7);
			woodBox(i, 9);
		}
		for (i = 1; i <= 13; i+=2){//rij 6/8
			woodBox(i, 6);
			woodBox(i, 8);
		}
		for (i = 3; i <= 11; i+=2){//rij 4/10
			woodBox(i, 4);
			woodBox(i, 10);
		}
		for (i = 4; i <= 10; i++){//rij 3/11
			woodBox(i, 3);
			woodBox(i, 11);
		}
		for (i = 5; i <= 9; i+=2){//rij 2/12
			woodBox(i, 2);
			woodBox(i, 12);
		}
		for (i = 6; i <= 8; i++){//rij 1/13
			woodBox(i, 1);
			woodBox(i, 13);
		}
	}
	else if (level == 3){
		uint8_t seed = 10;
		uint8_t x;
		uint8_t y;
		uint8_t QX;
		
		if(SR == 1){
			while(seed >= 10){
				Serial.println("loop");
				if(Serial.available()){
					seed = Serial.read() -48;
					Serial.println("READ");
					Serial.println(seed);
					if (seed>=0 && seed <= 9)
					{
						Serial.print("seed");
						Serial.println(seed);
						randomSeed(seed);
					}
					
				}
				delay(1);
			}
		}
		
		for(QX = 0; QX < 123; QX++){
			x = random(1,14);
			y = random(1,14);
			if(x == 1 && y == 1 || x == 2 && y == 1 || x == 3 && y == 1 ||x == 1 && y == 2 || x == 1 && y == 3 ||
			x == 13 && y == 13 || x == 12 && y == 13 || x == 11 && y == 13 || x == 13 && y == 12 || x == 13 && y == 11){
				QX--;
			}
			else if((x & 0x01) == 0 && (y & 0x01) == 0){
				QX--;
			}
			else{
				woodBox(x,y);
			}
		}
	}
	else{
		return;
	}
} //Obstacle