/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include <vector>
#include "game.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "ship.h"
#include "largeAsteroid.h"
#include "mediumAsteroid.h"
#include "smallAsteroid.h"
#include "bullet.h"

#define LARGE_ASTEROID_COLLISION 16
#define MEDIUM_ASTEROID_COLLISION 8
#define SMALL_ASTEROID_COLLISION 4

#include <limits>
#include <algorithm>
using namespace std;


/***************************************
* GAME CONSTRUCTOR
***************************************/
Game::Game(Point tl, Point br)
	: topLeft(tl), bottomRight(br)
{
	score = 0;

	for (int i = 1; i <= 5; i++)
	{
		Asteroid * theAst = new LargeAsteroid;
		asteroids.push_back(theAst);
	}

}
/****************************************
* GAME DESTRUCTOR
****************************************/
Game :: ~Game()
{
	

}
// You may find this function helpful...
/***************************************
* GAME :: HANDLE INPUT
* accept input from the user
***************************************/
void Game::handleInput(const Interface & ui)
{
	// Change the direction of the rifle
	if (ui.isLeft())
	{
		ship.moveLeft();
	}

	if (ui.isRight())
	{
		ship.moveRight();
	}

	if (ui.isUp())
	{
		ship.setPropulsion(true);
		ship.moveForward();
	}

	// Check for "Spacebar
	if (ui.isSpace())
	{
		if (ship.isAlive())
		{
			Bullet newBullet;
			newBullet.fire(ship.getPoint(), ship.getAngle(), ship.getVelocity());

 			bullets.push_back(newBullet);
			bulletsTime.push_back(0);
		}
	}
}

/*********************************************
* GAME :: DRAW
* Draw everything on the screen
*********************************************/
void Game::draw(const Interface & ui)
{
	if (ship.isAlive())
	{
		ship.draw();
		ship.setPropulsion(false);
	}
	
	for (int i = 0; i < asteroids.size(); i++)
	{
		if (asteroids[i]->isAlive())
			asteroids[i]->draw();
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].draw();
		}
	}

	Point scorePosition(-190, 190);
	drawNumber(scorePosition, score);

	Point gameOver(-35, 0);
	if (!ship.isAlive())
		drawText(gameOver, "GAME OVER");
}

/***************************************
* GAME :: ADVANCE
* advance the game one unit of time
***************************************/
void Game::advance()
{
	advanceAsteroids();
	advanceBullets();
	ship.advance();
	handleCollisions();
	cleanUpZombies();
}

/***************************************
* GAME :: ADVANCE ASTEROIDS
* Go through each asteroid and advance it.
***************************************/
void Game::advanceAsteroids()
{
	for (int i = 0; i < asteroids.size(); i++)
		asteroids[i]->advance();
}

/***************************************
* GAME :: ADVANCE BULLETS
* Go through each bullet and advance it.
***************************************/
void Game::advanceBullets()
{
	// Move each of the bullets forward if it is alive
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			// this bullet is alive, so tell it to move forward
			bullets[i].advance();
			bulletsTime[i]++;
			
			if (bulletsTime[i] == 40)
			{
				// the bullet has left the screen
				bullets[i].kill();
			} 

		}
	}
}

/**************************************************************************
* GAME :: HANDLE COLLISIONS
* Check for a collision between objects.
**************************************************************************/
void Game::handleCollisions()
{
	// now check for a hit (if it is close enough to any live bullets)
	for (int i = 0; i < bullets.size(); i++)
	// this bullet is alive, see if its too close
	// check if the asteroid is at this point (in case it was hit)
		for (int j = 0; j < asteroids.size(); j++)
			if (asteroids[j]->isAlive() && bullets[i].isAlive())
			{
				if (getClosestDistance(bullets[i], *asteroids[j]) < asteroids[j]->getCollisionSize())
				{
					bullets[i].kill();
					asteroids[j]->kill();
					switch (asteroids[j]->getType())
					{
					case 'L':
						destroyLargeAsteroid(asteroids, j);
						score += 1;
						break;
										
					case 'M':
						destroyMediumAsteroid(asteroids, j);
						score += 3;
						break;

					case 'S':
						score += 5;
						break;
					}
				}
				
			}
			
	//collision between asteroids and the ship
	for (int j = 0; j < asteroids.size(); j++)
		if (getClosestDistance(ship, *asteroids[j]) < asteroids[j]->getCollisionSize())
			ship.kill();
	
}


/**************************************************************************
* GAME :: CLEAN UP ZOMBIES
* Remove any dead objects
**************************************************************************/
void Game::cleanUpZombies()
{
	// Look for dead bullets
	vector<Bullet>::iterator bulletIt = bullets.begin();
	vector<int>::iterator bulletTimeIt = bulletsTime.begin();
	while (bulletIt != bullets.end())
	{
		Bullet bullet = *bulletIt;
		int bulletTime = *bulletTimeIt;
		
		if (!bullet.isAlive())
		{
			bulletIt = bullets.erase(bulletIt);
			bulletTimeIt = bulletsTime.erase(bulletTimeIt);
		}
		else
		{
			bulletTimeIt++;
			bulletIt++;
		}
	}

	// Look for dead asteroids
	vector<Asteroid*>::iterator asteroidIt = asteroids.begin();
	while (asteroidIt != asteroids.end())
	{
		Asteroid * asteroid = *asteroidIt;
		
		if (!asteroid->isAlive())
		{
			asteroidIt = asteroids.erase(asteroidIt);
			/*DEALLOCATING ASTEROID*/
			delete asteroid;
		}
		else
			asteroidIt++;
	}
	
}

/**************************************************************************
* GAME :: DESTROY LARGE ASTEROID
* Create the asteroids after a large asteroid is destroyed.
**************************************************************************/
void Game::destroyLargeAsteroid(std::vector < Asteroid*>  &asteroids, int i)
{
	Asteroid * m1 = new MediumAsteroid(asteroids[i]->getPoint(), 
		asteroids[i]->getVelocity().getDx(), asteroids[i]->getVelocity().getDy() + 1);
	Asteroid * m2 = new MediumAsteroid(asteroids[i]->getPoint(),
		asteroids[i]->getVelocity().getDx(), asteroids[i]->getVelocity().getDy() - 1);
	Asteroid * m3 = new SmallAsteroid(asteroids[i]->getPoint(),
		asteroids[i]->getVelocity().getDx() + 2, asteroids[i]->getVelocity().getDy());
	Asteroid * m4 = new LargeAsteroid;

	asteroids.push_back(m1);
	asteroids.push_back(m2);
	asteroids.push_back(m3);
	asteroids.push_back(m4);
}

/**************************************************************************
* GAME :: DESTROY MEDIUM ASTEROID
* Create the asteroids after a medium asteroid is destroyed.
**************************************************************************/
void Game::destroyMediumAsteroid(std::vector < Asteroid*>  &asteroids, int i)
{
	Asteroid * m1 = new SmallAsteroid(asteroids[i]->getPoint(),
		asteroids[i]->getVelocity().getDx() + 3, asteroids[i]->getVelocity().getDy());
	Asteroid * m2 = new SmallAsteroid(asteroids[i]->getPoint(),
		asteroids[i]->getVelocity().getDx() - 3, asteroids[i]->getVelocity().getDy());
	asteroids.push_back(m1);
	asteroids.push_back(m2);
}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game::getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
	// find the maximum distance traveled
	float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
	dMax = max(dMax, abs(obj2.getVelocity().getDx()));
	dMax = max(dMax, abs(obj2.getVelocity().getDy()));
	dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

	float distMin = std::numeric_limits<float>::max();
	for (float i = 0.0; i <= dMax; i++)
	{
		Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
			obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
		Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
			obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

		float xDiff = point1.getX() - point2.getX();
		float yDiff = point1.getY() - point2.getY();

		float distSquared = (xDiff * xDiff) + (yDiff * yDiff);

		distMin = min(distMin, distSquared);
	}

	return sqrt(distMin);
}


