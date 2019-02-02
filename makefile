###############################################################
# Program:
#     Project 13, Asteroids
#     Brother Cook, CS165
# Author:
#     Frank Rincon
# Summary:
#     This is the completed asteroid project. 
# Above and Beyond
#     -Score added to the game.
#      Large asteroid: 1
#      Medium asteroid: 3
#      Small asteroid: 5
#     -When the ship is hit by an asteroid, a message
#      that says "Game Over" appears on the screen.
#     -After a large asteroid is destroyed, a new 
#      appears on the screen.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o asteroid.o smallAsteroid.o mediumAsteroid.o largeAsteroid.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o velocity.o flyingObject.o ship.o bullet.o asteroid.o smallAsteroid.o mediumAsteroid.o largeAsteroid.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o       Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o   Handles input events
#    point.o        The position on the screen
#    game.o         Handles the game interaction
#    velocity.o     Velocity (speed and direction)
#    flyingObject.o Base class for all flying objects
#    ship.o         The player's ship
#    bullet.o       The bullets fired from the ship
#    asteroids.o        Contains all of the Rock classes
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

driver.o: driver.cpp game.h
	g++ -c driver.cpp

game.o: game.cpp game.h uiDraw.h uiInteract.h point.h velocity.h flyingObject.h bullet.h asteroid.h ship.h smallAsteroid.h mediumAsteroid.h largeAsteroid.h
	g++ -c game.cpp

velocity.o: velocity.cpp velocity.h point.h
	g++ -c velocity.cpp

flyingObject.o: flyingObject.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c flyingObject.cpp

ship.o: ship.cpp ship.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c ship.cpp

bullet.o: bullet.cpp bullet.h flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

asteroid.o: asteroid.cpp asteroid.h flyingObject.h
	g++ -c asteroid.cpp

smallAsteroid.o: asteroid.h smallAsteroid.h smallAsteroid.cpp
	g++ -c smallAsteroid.cpp

mediumAsteroid.o: asteroid.h mediumAsteroid.h mediumAsteroid.cpp
	g++ -c mediumAsteroid.cpp

largeAsteroid.o: asteroid.h largeAsteroid.h largeAsteroid.cpp
	g++ -c largeAsteroid.cpp


###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
