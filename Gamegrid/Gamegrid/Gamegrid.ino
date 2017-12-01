#include "Test.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <Wire.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include "Grid.h"
#include "Wall.h"
#include "Obstacle.h"
#include "Character.h"
#include "Bom.h"

//Declare display !
MI0283QT9 lcd;  //MI0283QT9 Adapter v1

//outerGrid gridout;

GridClass gridFH;
OuterWall wallOut;
InnerWall wallIn;
Obstacle OB;
Character Characters;
Bom bom;

int main(void)
{
   // init();
    Serial.begin(9600);   
    //	MI0283QT9 lcd;  //MI0283QT9 Adapter v1
    uint8_t clear_bg=0x00; //0x80 = dont clear background for fonts (only for DisplayXXX)
	
    //init display
    lcd.begin();

    //clear screen
    lcd.fillScreen(RGB(255,255,255));
	//OuterWall();
//	gridFH.GritPX;
	//lcd.drawInteger (30, 30, gridFH.GridF(5), 20,RGB(2,30,240), RGB(0,0,0), 5);
	Serial.println(gridFH.GridF(5));
	wallOut.OuterWallP();
	wallIn.InnerWallP();
	OB.ObstacleDR(2);
	Characters.MoveA(2, 1);
	Characters.MoveA(3, 3);
	Characters.MoveB(11, 11);
	Characters.MoveB(13, 12);
	bom.BomXY(1,3);
	bom.BomXY(11,13);
	//Serial.println(OB.Locations[1][1]);
	//outerGrid.printOuterGrid();
	
	//inergrid();
    while (1) 
    {
		
    }
}