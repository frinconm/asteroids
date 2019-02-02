/*************************************************************
* File: velocity.h
* Author: Frank Rincon
*
* Description: Contains the definition of the velocity class.
*
**************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

/*****************************************
* Velocity
* This class keeps data about lander's
* speed.
*****************************************/
class Velocity
{
private:

	float dx;
	float dy;

public:

	Velocity();
	Velocity(float dx, float dy);

	float getDx() const;
	float getDy() const;

	void setDx(float dx);
	void setDy(float dy);
};

#endif /* VELOCITY_H */