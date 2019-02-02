#ifndef MEDIUMASTEROID_H
#define MEDIUMASTEROID_H

#include "asteroid.h"

#define MEDIUMASTEROID_SPEED 2

class MediumAsteroid : public Asteroid
{
public:

	MediumAsteroid(Point point, float dx, float dy);

	virtual void advance();
	virtual void draw();

};

#endif 