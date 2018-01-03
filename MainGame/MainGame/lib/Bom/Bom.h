#ifndef _BOM_H_
#define _BOM_H_

#include "../Grid/Grid.h"
#include "../Data/Data.h"
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <ArduinoNunchuk.h>


class Bom
{
	//variables
	public:
	protected:
	private:
	MI0283QT9 lcd;
	int bomY;
	int bomX;
	uint8_t bombA = 0;
	uint8_t bombB = 0;
	//functions
	public:
	BomXY(int X, int Y);
	BomExpl(int X, int Y);
	BomTrack(int bomX, int bomY, int character);
	BomDelete(int bomX, int bomY, int character);
	void PlaceBomA(int XA, int YA, int XB, int YB, int character, int bomBinnen, int * counterBomExplosionA, int * counterBomDeleteA);
	void PlaceBomB(int XA, int YA, int XB, int YB, int character, int bomBinnen, int * counterBomExplosionB, int * counterBomDeleteB);
	protected:
	private:

}; //Bom

#endif //_BOM_H_