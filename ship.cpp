#include "ship.h"
#include "point.h"
#include "uiDraw.h"

#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void Ship::draw() 
{
	drawShip(point, angle, propulsion);
}

void Ship::moveLeft()
{
	angle += ROTATE_AMOUNT;

	if (angle > ANGLE_MAX)
	{
		angle = ANGLE_MIN;
	}

}

void Ship::moveRight()
{ 
	angle -= ROTATE_AMOUNT;

	if (angle < ANGLE_MIN)
	{
		angle = ANGLE_MAX;
	}
}

void Ship::moveForward()
{
	velocity.setDx(velocity.getDx() + (THRUST_AMOUNT * (cos(M_PI / 180.0 * (angle + 90)))));
	velocity.setDy(velocity.getDy() + (THRUST_AMOUNT * (sin(M_PI / 180.0 * (angle + 90)))));
}
