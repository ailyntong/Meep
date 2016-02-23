/*
A one-time powerup that gives Player a life
by reducing enemy score by 1.
NOTE: will do nothing if enemy score is 0.

Author: Ailyn Tong
*/
#ifndef LIFE_H
#define LIFE_H

#include "Entity.h"
#include "Player.h"

class Life : public Entity {
public:
	/*Constructor*/
	Life();

	void take(Player *p);	//takes a life from specified player

	void draw(sf::RenderWindow *window);	//draws sprite only if life has not been taken

private:
	bool isTaken;	//whether or not life has been taken
};

#endif