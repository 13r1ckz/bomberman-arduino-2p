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

//functions
public:
	BomXY(int X, int Y);
	BomExpl(int X, int Y);
	BomTrack(int bomX, int bomY);
	BomDelete(int bomX, int bomY);
protected:
private:

}; //Bom

#endif //__BOM_H__
