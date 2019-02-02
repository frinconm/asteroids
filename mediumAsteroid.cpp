#include "mediumAsteroid.h"

#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

MediumAsteroid::MediumAsteroid(Point point, float dx, float dy)
{
	this->angle = random(0,360);

	this->point.setX(point.getX());
	this->point.setY(point.getY());

	this->velocity.setDx(dx);
	this->velocity.setDy(dy);

	astType = 'M';

	collisionSize = 8;

	this->mIsAlive = true;
}

void MediumAsteroid::advance()
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

	angle += 5;

	return;
}

void MediumAsteroid::draw()
{
	drawMediumAsteroid(point, angle);
}