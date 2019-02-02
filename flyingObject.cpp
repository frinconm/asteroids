/*************************************************************
* File: FlyingObject.cpp
* Author: Frank Rincon
*
* Description: Contains the implementations of the
*  method bodies for the flying object class.
*
*************************************************************/

#include "flyingObject.h"

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

/*****************
* Getters
*****************/
Point FlyingObject::getPoint() const
{
	return this->point;
}

Velocity FlyingObject::getVelocity() const
{
	return this->velocity;
}

bool FlyingObject::isAlive() const
{
	return this->mIsAlive;
}

/*****************
* Setters
*****************/

void FlyingObject::setPoint(Point point)
{
	this->point = point;
}

void FlyingObject::setVelocity(Velocity velocity)
{
	this->velocity = velocity;
}

void FlyingObject::kill()
{
	mIsAlive = false;
}

/*******************************************
* This method changes a flying object's
* position on the screen.
********************************************/
void FlyingObject::advance()
{
	if (point.getY() > 200)
		point.setY(-200);
	if (point.getY() < -200)
		point.setY(200);
	else
		point.addY(velocity.getDy());
	
	if (point.getX() > 200)
		point.setX(-200);
	if (point.getX() < -200)
		point.setX(200);
	else
		point.addX(velocity.getDx());

	return;
}
