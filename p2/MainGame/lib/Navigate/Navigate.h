#ifndef __NAVIGATE_H__
#define __NAVIGATE_H__

#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <ArduinoNunchuk.h>
#include "../Data/Data.h"
#include "../Grid/Grid.h"
#include "../Character/Character.h"

//extern int counter = 0;
//extern int nunchukX = 1;
//extern int nunchukY = 1;
class Navigate
{
//variables
public:
	int counter = 0;
protected:
private:

//functions
public:
	navigate();
	navigatestart(char button);
	
};

#endif //__NAVIGATE_H__
