#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#define ANGLE_START 0
#define ANGLE_MAX 360
#define ANGLE_MIN 0

#include "point.h"
#include "velocity.h"
#include "flyingObject.h"

// Put your Ship class here
class Ship: public FlyingObject
{
private:

	bool propulsion;
	float angle;
	
public:
	Ship() { point; angle = ANGLE_START; mIsAlive = true; propulsion = false; }

	/****************
	* Basic Getters
	****************/
	float getAngle() const { return angle; }
	Point getPoint() const { return point; }

	/*****************
	* Drawing
	*****************/
	void draw();

	/*****************
	* Movement
	*****************/
	void moveLeft();
	void moveRight();
	void moveForward();

	void setPropulsion(bool propulsion) { this->propulsion = propulsion; }

};

#endif /* ship_h */
