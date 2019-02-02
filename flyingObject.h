/*************************************************************
* File: FlyingObject.h
* Author: Frank Rincon
*
* Description: Contains the definition of the flying object
* class.
*
**************************************************************/

#ifndef FlyingObject_H
#define FlyingObject_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

/*********************************************
* FLYING OBJECT
* It holds the behavior of a flying object.
*********************************************/
class FlyingObject
{
protected:

	Point point;
	Velocity velocity;
	bool mIsAlive;

public:

	//Getters
	Point getPoint() const;
	Velocity getVelocity() const;
	bool isAlive() const;

	//Setters
	void setPoint(Point point);
	void setVelocity(Velocity velocity);
	void kill();

	void advance();

};

#endif /* FlyingObject_H */