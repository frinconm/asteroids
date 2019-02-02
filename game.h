/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "point.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "ship.h"
#include "asteroid.h"
#include "largeAsteroid.h"
#include "mediumAsteroid.h"
#include "smallAsteroid.h"
#include "bullet.h"
 /*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
	/*********************************************
	* Constructor
	* Initializes the game
	*********************************************/
	Game(Point tl, Point br);
	~Game();

	/*********************************************
	* Function: handleInput
	* Description: Takes actions according to whatever
	*  keys the user has pressed.
	*********************************************/
	void handleInput(const Interface & ui);

	/*********************************************
	* Function: advance
	* Description: Move everything forward one
	*  step in time.
	*********************************************/
	void advance();

	/*********************************************
	* Function: draw
	* Description: draws everything for the game.
	*********************************************/
	void draw(const Interface & ui);

private:
	// The coordinates of the screen
	Point topLeft;
	Point bottomRight;
	Ship ship;
	std::vector<Bullet> bullets;
	std::vector<int> bulletsTime;
	std::vector<Asteroid *> asteroids;

	void advanceAsteroids();
	void advanceBullets();
	void cleanUpZombies();
	void handleCollisions();
	float getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const;
	void destroyLargeAsteroid(std::vector < Asteroid*>  &asteroids, int i);
	void destroyMediumAsteroid(std::vector < Asteroid*>  &asteroids, int i);
	int score;
	
};



#endif /* GAME_H */
