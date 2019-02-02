#include "smallAsteroid.h"

#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

SmallAsteroid::SmallAsteroid(Point point, float dx, float dy)
{
	this->angle = random(0,360);

	this->point.setX(point.getX());
	this->point.setY(point.getY());

	this->velocity.setDx(dx);
	this->velocity.setDy(dy);

	astType = 'S';

	collisionSize = 4;

	this->mIsAlive = true;
}

void SmallAsteroid::advance()
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

	angle += 10;

	return;
}

void SmallAsteroid::draw()
{
	drawSmallAsteroid(point, angle);
}