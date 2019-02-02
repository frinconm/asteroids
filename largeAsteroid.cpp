#include "largeAsteroid.h"

#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

LargeAsteroid::LargeAsteroid()
{
	angle = random(0, 360);

	int position = random(1,3);
	mIsAlive = true;

	switch (position)
	{
	case 1:
	{
		point.setX(random(-200, -50));
		break;
	}
	case 2:
	{
		point.setX(random(50, 200));
		break;
	}
	}
	position = random(1, 3);
		
	switch (position)
	{
	case 1:
	{
		point.setY(random(-200, -50));
		break;
	}
	case 2:
	{
		point.setY(random(50, 200));
		break;
	}
	}
	
	collisionSize = 16;

	astType = 'L';

	velocity.setDx(LARGEASTEROID_SPEED * (-cos(M_PI / 180.0 * angle)));
	velocity.setDy(LARGEASTEROID_SPEED * (sin(M_PI / 180.0 * angle)));
}

void LargeAsteroid::advance()
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

	angle += 2;

	return;
}

void LargeAsteroid::draw()
{
	drawLargeAsteroid(point, angle);
}