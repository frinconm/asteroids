#ifndef ASTEROID_H
#define ASTEROID_H

#include "flyingObject.h"

class Asteroid : public FlyingObject
{
protected:

	float angle; 
	char astType;
	int collisionSize;
	
public:

	float getAngle() const { return angle; }
	char getType() const { return astType; }
	int getCollisionSize() const{ return collisionSize;  }
	virtual void advance() {};
	virtual void draw() {}

};

#endif 