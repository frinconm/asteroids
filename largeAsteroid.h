#ifndef LARGEASTEROID_H
#define LARGEASTEROID_H

#define LARGEASTEROID_SPEED 1

#include "asteroid.h"

class LargeAsteroid : public Asteroid
{
public:

	LargeAsteroid();

	virtual void advance();
	virtual void draw();

};

#endif 