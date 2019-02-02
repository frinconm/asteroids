#include "bullet.h"

#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/*********************************
* DEFAULT CONSTRUCTOR
**********************************/
Bullet::Bullet()
{
	mIsAlive = true;
}

/*******************************************
* This method draws a bird on the screen.
********************************************/
void Bullet::draw()
{
	drawDot(getPoint());

	return;
}

/*******************************************
* This method sets a bullet's velocity
* according to the ship's angle.
********************************************/
void Bullet::fire(Point point, float angle, Velocity vel)
{
	this->point.setX(point.getX());
	this->point.setY(point.getY());
	
	velocity.setDy( vel.getDy() + 5 * sin(M_PI / 180 * (angle + 90)));
	velocity.setDx( vel.getDx() + 5 * cos(M_PI / 180 * (angle + 90)));
	
	return;
 }
