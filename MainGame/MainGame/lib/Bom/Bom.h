#ifndef __BOM_H__
#define __BOM_H__

#include "../Grid/Grid.h"
#include "../Data/Data.h"
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <ArduinoNunchuk.h>
#include <SoftwareSerial.h>


class Bom
{
//variables
public:
protected:
private:
	int bomY;
	int bomX;
	uint8_t bomb = 0;
//functions
public:
	BomXY(int X, int Y);
	BomExpl(int X, int Y);
	BomTrack(int bomX, int bomY, int character);
	BomDelete(int bomX, int bomY, int character);
	void PlaceBom(int XA, int YA, int XB, int YB, int character, int bomBinnen, int * counterBomExplosion, int * counterBomDelete);
protected:
private:

}; //Bom

#endif //__BOM_H__
