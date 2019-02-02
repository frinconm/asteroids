#ifndef bullet_h
#define bullet_h

#define BULLET_LIFE 40

// Put your Bullet class here

#include "flyingObject.h"

class Bullet : public FlyingObject
{
public:

	//Default constructor
	Bullet();

	void draw();
	void fire(Point point, float angle, Velocity vel);

};

#endif /* bullet_h */
