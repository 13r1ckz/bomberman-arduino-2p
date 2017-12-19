#include "outerGrid.h"

#if defined(_USING_GraphicsLib)
#if defined(_USING_MI0283QT9)

void outerGrid_::Grid(int X){
	return (X*16);
}

void outerGrid_::printOuterGrid(void)
{
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
}

outerGrid_ outerGrid;

#endif
#endif