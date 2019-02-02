#ifndef SMALLASTEROID_H
#define SMALLASTEROID_H

#include "asteroid.h"

#define SMALLASTEROID_SPEED 4

class SmallAsteroid : public Asteroid
{
public:

	SmallAsteroid(Point point, float dx, float dy);

	virtual void advance();
	virtual void draw();

};

#endif 