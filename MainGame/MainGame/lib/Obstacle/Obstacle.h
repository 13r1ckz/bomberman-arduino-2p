#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include "../Grid/Grid.h"
#include "../Data/Data.h"
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <SoftwareSerial.h>
#include <Arduino.h>

class Obstacle
{
//variables
public:
uint8_t seed = 0;
protected:
private:

//functions
public:
	woodBox(int X, int Y);
	ObstacleDR(int Level, uint8_t SR);
	setseed(uint8_t seed);
protected:
private:

}; //Obstacle

#endif //__OBSTACLE_H__
