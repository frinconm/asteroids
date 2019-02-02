/*************************************************************
* File: velocity.cpp
* Author: Frank Rincon
*
* Description: Contains the implementations of the
*  method bodies for the velocity class.
*
*************************************************************/

#include "velocity.h"

/*****************
* Constructor
*****************/
Velocity::Velocity()
{
	dx = 0;
	dy = 0;
}

Velocity::Velocity(float dx, float dy)
{
	this->dx = dx;
	this->dy = dy;
}

/*****************
* Getters
*****************/
float Velocity::getDx() const
{
	return dx;
}

float Velocity::getDy() const
{
	return dy;
}

/*****************
* Setters
*****************/
void Velocity::setDx(float dx)
{
	this->dx = dx;
}

void Velocity::setDy(float dy)
{
	this->dy = dy;
}