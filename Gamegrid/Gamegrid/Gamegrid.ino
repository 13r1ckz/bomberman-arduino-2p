#include "Test.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <Wire.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include "Grid.h"
#include "OuterWall.h"

//Declare display !
MI0283QT9 lcd;  //MI0283QT9 Adapter v1

//outerGrid gridout;

GridClass gridFH;
OuterWall wallOut;
//int Grid(int X){
	//return (X*16);
//}
/*int OuterWall(){
	int i , j;
	int X = 0;
	int Y = 0;
	int outer[][2] = {{1,1}, {2,1}, {3,1}, {4,1}, {5,1}, {6,1},	{7,1}, {8,1}, {9,1}, {10,1}, {11,1}, {12,1}, {13,1}, {14,1}, {15,1},
					{2,2}, {2,15},
					{3,2}, {3,15},
					{4,2}, {4,15},
					{5,2}, {5,15},
					{6,2}, {6,15},
					{7,2}, {7,15},
					{8,2}, {8,15},
					{9,2}, {9,15},
					{10,2}, {10,15},
					{11,2}, {11,15},
					{12,2}, {12,15},
					{13,2}, {13,15},
					{14,2}, {14,15},
					{1,15}, {2,15}, {3,15}, {4,15}, {5,15}, {6,15},	{7,15}, {8,15}, {9,15}, {10,15}, {11,15}, {12,15}, {13,15}, {14,15}, {15,15}};
	
	for(i = 0; i < 15; i++){
		lcd.fillRect(Grid(X),Grid(Y),16,16, 0xFFFFFF);
		lcd.fillRect((Grid(X)+1),(Grid(Y)+1),14,14, 0x000);
		X = X + 1;
	}
	for(i = 0; i < 16; i++){
		lcd.fillRect(0,Grid(Y),16,16, 0xFFFFFF);
		lcd.fillRect(1,(Grid(Y)+1),14,14, 0x000);
		lcd.fillRect(224,Grid(Y),16,16, 0xFFFFFF);
		lcd.fillRect(225,(Grid(Y)+1),14,14, 0x000);
		Y = Y + 1;
	}
	X = 0;
	for(i = 0; i < 15; i++){
		lcd.fillRect(Grid(X),224,16,16, 0xFFFFFF);
		lcd.fillRect((Grid(X)+1),(225),14,14, 0x000);
		X = X + 1;
	}
	return outer;
}*/
//int inergrid(){
	//int i, j, X, Y, a;
	//int x;
	//int y;
	//int inner[][2] = {{3,3}, {5,3}, {7,3}, {9,3}, {11,3}, {13,3}, 
					//{3,5}, {5,5}, {7,5}, {9,5}, {11,5}, {13,5},
					//{3,7}, {5,7}, {7,7}, {9,7}, {11,7}, {13,7},
					//{3,9}, {5,9}, {7,9}, {9,9}, {11,9}, {13,9},
					//{3,11}, {5,11}, {7,11}, {9,11}, {11,11}, {13,11},
					//{3,13}, {5,13}, {7,13}, {9,13}, {11,13}, {13,13}};
	//X = 2;
	//Y = 2;
	//for(i = 0; i < 6; i++){
		//for(j = 0; j < 6; j++){
			//lcd.fillRect((Grid(X)),(Grid(Y)),16,16, 0x000);
			//X = X + 2;
			//Serial.print("x: ");
			//Serial.println(X);
			//Serial.println(Grid(X));
		//}
		//X = 2;
		//Y = Y + 2;
		//Serial.print("y: ");
		//Serial.println(Y);
		//Serial.println(Grid(Y));
	//}
	//return inner;
//}
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
	//OuterWall();
//	gridFH.GritPX;
	lcd.drawInteger (30, 30, gridFH.GridF(5), 20,RGB(2,30,240), RGB(0,0,0), 5);
	Serial.println(gridFH.GridF(5));
	wallOut.OuterWallP();
	//outerGrid.printOuterGrid();
	
	//inergrid();
    while (1) 
    {
		
    }
}